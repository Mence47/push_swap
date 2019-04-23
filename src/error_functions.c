/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 22:11:17 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/09 17:27:40 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	ft_abs(int v)
{
	return (v * ((v > 0) - (v < 0)));
}

int	ft_dublicates(t_stack *stack)
{
	t_stack *i;
	t_stack *j;

	i = stack;
	while (i != NULL)
	{
		j = i;
		while (j->next != NULL)
		{
			if (i->elem->num == j->next->elem->num)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}

int	ft_print_error(t_stack **a, t_stack **b)
{
	ft_del_list(a);
	ft_del_list(b);
	ft_putstr_fd("Error\n", 2);
	return (-1);
}

int	ft_check_command(char *tmp, char **line)
{
	char	**legit;
	int		i;

	i = 0;
	legit = ft_strsplit("sa sb ss pa pb ra rb rr rra rrb rrr", ' ');
	while (legit[i] != NULL)
	{
		if (ft_strstr(legit[i], tmp) != NULL)
		{
			ft_clear_split(legit);
			return (0);
		}
		i++;
	}
	ft_strdel(&tmp);
	ft_strdel(line);
	ft_clear_split(legit);
	return (1);
}

int	ft_check_str(char *str)
{
	if (ft_strlen(str) == ft_strlen("2147483647"))
	{
		if (ft_strcmp(str, "2147483647") > 0)
			return (1);
	}
	else if (ft_strlen(str) == ft_strlen("-2147483648"))
	{
		if (ft_strcmp(str, "-2147483648") > 0)
			return (1);
	}
	else if (ft_strlen(str) > ft_strlen("-2147483648"))
		return (1);
	else if (ft_strlen(str) > ft_strlen("2147483647"))
		return (1);
	while (*str)
	{
		if (*str == '-')
			str++;
		if (ft_isdigit(*str) == 0)
			return (1);
		str++;
	}
	return (0);
}
