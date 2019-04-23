/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:54:29 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/09 17:27:44 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static int	ft_find_pivot(t_stack *a)
{
	int *sorted;
	int size;
	int i;

	size = ft_find_size(a);
	sorted = (int *)malloc(sizeof(int) * size + 1);
	i = 0;
	while (a != NULL && a->elem->tag == 0)
	{
		sorted[i++] = a->elem->num;
		a = a->next;
	}
	ft_bubble_sort(sorted, size, 1);
	i = sorted[size % 2 == 0 ? size / 2 - 1 : size / 2];
	free(sorted);
	return (i);
}

static void	ft_return(t_stack **a, t_stack **b, char **commands, int top)
{
	ft_rra_ps(a, b, commands);
	if ((*a)->elem->num > top)
	{
		ft_ra_ps(a, b, commands);
		return ;
	}
	ft_return(a, b, commands, top);
}

static void	ft_push_pivot(t_stack **a, t_stack **b, char **commands, int p)
{
	int direction;

	direction = ft_find_way(*a, p);
	while ((*a)->elem->num != p)
	{
		if (direction == 1)
			ft_rra_ps(a, b, commands);
		else
			ft_ra_ps(a, b, commands);
	}
	(*a)->elem->tag = 1;
	ft_pb_ps(a, b, commands);
	if ((*a) != NULL && ft_is_tag_elem(*a) == 1)
		ft_return(a, b, commands, ft_next_tag(*a));
}

static int	ft_take_pivot(t_stack **a, t_stack **b, char **commands)
{
	if (*a == NULL)
		return (-1);
	if ((*a)->elem->tag == 0)
		return (ft_find_pivot(*a));
	while (*a != NULL && (*a)->elem->tag == 1)
		ft_pb_ps(a, b, commands);
	return (ft_take_pivot(a, b, commands));
}

void		ft_sort_a(t_stack **a, t_stack **b, char **commands)
{
	int pivot;

	pivot = ft_take_pivot(a, b, commands);
	if (ft_find_size(*a) <= 20 && (*a) != NULL)
	{
		ft_insertion_a(a, b, commands);
		ft_sort_a(a, b, commands);
	}
	while (*a != NULL)
		if ((*a)->elem->tag == 1)
		{
			ft_push_pivot(a, b, commands, pivot);
			ft_sort_a(a, b, commands);
		}
		else if ((*a)->elem->num == pivot)
		{
			(*a)->elem->tag = 1;
			ft_ra_ps(a, b, commands);
		}
		else if ((*a)->elem->num < pivot)
			ft_pb_ps(a, b, commands);
		else if ((*a)->elem->num > pivot)
			ft_ra_ps(a, b, commands);
}
