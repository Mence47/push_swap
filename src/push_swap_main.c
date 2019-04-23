/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:18:52 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/01 12:58:58 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

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
	char	*commands;
	int		i;

	if (argc == 1)
		return (0);
	a = NULL;
	b = NULL;
	i = argc - 1;
	while (i > 0)
		if (ft_add_elem(&a, argv[i--]) == -1)
			return (ft_print_error(&a, &b));
	if (ft_dublicates(a))
		return (ft_print_error(&a, &b));
	commands = ft_quick_sort(&a, &b);
	ft_optimaze(&commands);
	ft_putstr(commands);
	if (commands[0] != '\0')
		ft_putchar('\n');
	ft_strdel(&commands);
	return (0);
}
