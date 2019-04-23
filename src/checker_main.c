/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:45:17 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/01 13:10:27 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_is_sorted(t_stack **a, t_stack **b)
{
	t_stack	*root;

	if (*b != NULL)
	{
		ft_del_list(a);
		ft_del_list(b);
		ft_putstr("KO\n");
		return (0);
	}
	root = *a;
	while (root->next != NULL)
	{
		if (root->elem->num > root->next->elem->num)
		{
			ft_del_list(a);
			ft_putstr("KO\n");
			return (0);
		}
		root = root->next;
	}
	ft_del_list(a);
	ft_putstr("OK\n");
	return (1);
}

static void	ft_execute_commands(char *str, t_stack **a, t_stack **b)
{
	char	**commands;
	char	**legit;
	int		i;

	commands = ft_strsplit(str, ' ');
	legit = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", ' ');
	i = 0;
	while (commands[i] != NULL)
	{
		ft_execute(a, b, ft_find_index(commands[i], legit));
		i++;
	}
	ft_clear_split(commands);
	ft_clear_split(legit);
}

static void	ft_add(t_stack **root, char *str)
{
	t_stack	*tmp;

	if (*root == NULL)
		*root = ft_create_elem(ft_atoi(str));
	else
	{
		tmp = ft_create_elem(ft_atoi(str));
		tmp->next = *root;
		*root = tmp;
	}
}

static int	ft_add_elem(t_stack **root, char *str)
{
	char	**ptr;
	int		i;

	i = 0;
	ptr = ft_strsplit(str, ' ');
	if (*ptr == NULL)
	{
		ft_clear_split(ptr);
		return (-1);
	}
	while (ptr[i] != NULL)
		i++;
	while (--i >= 0)
	{
		if (ft_check_str(ptr[i]))
		{
			ft_clear_split(ptr);
			return (-1);
		}
		ft_add(root, ptr[i]);
	}
	ft_clear_split(ptr);
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		i;
	char	*commands;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	i = argc - 1;
	while (i > 0)
		if (ft_add_elem(&a, argv[i--]) == -1)
			return (ft_print_error(&a, &b));
	if (ft_dublicates(a))
		return (ft_print_error(&a, &b));
	if (ft_get_commands(&commands) == -1)
		return (ft_print_error(&a, &b));
	ft_execute_commands(commands, &a, &b);
	ft_strdel(&commands);
	return (ft_is_sorted(&a, &b));
}
