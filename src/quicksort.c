/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:36:18 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/09 17:27:44 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_is_sorted(t_stack **a, t_stack **b)
{
	t_stack	*root;

	if (*b != NULL)
		return (0);
	root = *a;
	while (root->next != NULL)
	{
		if (root->elem->num > root->next->elem->num)
			return (0);
		root = root->next;
	}
	return (1);
}

int			ft_find_size(t_stack *a)
{
	int size;

	size = 0;
	while (a != NULL && a->elem->tag == 0)
	{
		size++;
		a = a->next;
	}
	return (size);
}

static int	ft_is_reverse_sorted(t_stack **a, t_stack **b)
{
	t_stack	*root;

	if (*a != NULL)
		return (0);
	root = *b;
	while (root->next != NULL)
	{
		if (root->elem->num < root->next->elem->num)
			return (0);
		root = root->next;
	}
	return (1);
}

char		*ft_quick_sort(t_stack **a, t_stack **b)
{
	char	*commands;

	commands = ft_strnew(0);
	if (ft_find_size(*a) <= 3)
		ft_sort_three_a(a, b, &commands);
	while (ft_is_sorted(a, b) == 0)
	{
		ft_sort_a(a, b, &commands);
		if (ft_is_reverse_sorted(a, b) == 1)
		{
			while (*b != NULL)
				ft_pa_ps(a, b, &commands);
			break ;
		}
		ft_sort_b(a, b, &commands);
	}
	ft_del_list(a);
	ft_del_list(b);
	return (commands);
}
