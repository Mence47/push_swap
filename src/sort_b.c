/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 22:43:50 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/09 17:27:44 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ft_return(t_stack **a, t_stack **b, char **commands, int top)
{
	ft_rrb_ps(a, b, commands);
	if ((*b)->elem->num < top)
	{
		ft_rb_ps(a, b, commands);
		return ;
	}
	ft_return(a, b, commands, top);
}

static void	ft_push_pivot(t_stack **a, t_stack **b, char **commands, int p)
{
	int direction;

	direction = ft_find_way(*b, p);
	while ((*b)->elem->num != p)
	{
		if (direction == 1)
			ft_rrb_ps(a, b, commands);
		else
			ft_rb_ps(a, b, commands);
	}
	(*b)->elem->tag = 1;
	ft_pa_ps(a, b, commands);
	if ((*b) != NULL && ft_is_tag_elem(*b) == 1)
		ft_return(a, b, commands, ft_next_tag(*b));
}

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
	ft_bubble_sort(sorted, size, -1);
	i = sorted[size % 2 == 0 ? size / 2 - 1 : size / 2];
	free(sorted);
	return (i);
}

static int	ft_take_pivot(t_stack **a, t_stack **b, char **commands)
{
	if (*b == NULL)
		return (-1);
	if ((*b)->elem->tag == 0)
		return (ft_find_pivot(*b));
	while (*b != NULL && (*b)->elem->tag == 1)
		ft_pa_ps(a, b, commands);
	return (ft_take_pivot(a, b, commands));
}

void		ft_sort_b(t_stack **a, t_stack **b, char **commands)
{
	int pivot;

	pivot = ft_take_pivot(a, b, commands);
	if (ft_find_size(*b) <= 20 && (*b) != NULL)
	{
		ft_insertion_b(a, b, commands);
		ft_sort_b(a, b, commands);
	}
	while (*b != NULL)
		if ((*b)->elem->tag == 1)
		{
			ft_push_pivot(a, b, commands, pivot);
			ft_sort_b(a, b, commands);
		}
		else if ((*b)->elem->num == pivot)
		{
			(*b)->elem->tag = 1;
			ft_rb_ps(a, b, commands);
		}
		else if ((*b)->elem->num > pivot)
			ft_pa_ps(a, b, commands);
		else if ((*b)->elem->num < pivot)
			ft_rb_ps(a, b, commands);
}
