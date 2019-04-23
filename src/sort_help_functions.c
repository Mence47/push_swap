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

int	ft_next_tag(t_stack *b)
{
	while (b != NULL)
	{
		if (b->elem->tag == 1)
			return (b->elem->num);
		b = b->next;
	}
	return (0);
}

int	ft_is_tag_elem(t_stack *root)
{
	while (root != NULL)
	{
		if (root->elem->tag == 1)
			return (1);
		root = root->next;
	}
	return (0);
}

int	ft_find_way(t_stack *a, int p)
{
	int size;
	int pivot_index;

	size = 0;
	pivot_index = 0;
	while (a != NULL)
	{
		size++;
		if (a->elem->num == p)
			pivot_index = size;
		a = a->next;
	}
	if (size % 2 == 1)
		size++;
	if (pivot_index > size / 2)
		return (1);
	return (0);
}

int	ft_max(t_stack *stack)
{
	int max;

	if (stack == NULL)
		return (-1);
	max = stack->elem->num;
	while (stack != NULL && stack->elem->tag == 0)
	{
		if (stack->elem->num > max)
			max = stack->elem->num;
		stack = stack->next;
	}
	return (max);
}

int	ft_min(t_stack *stack)
{
	int min;

	if (stack == NULL)
		return (-1);
	min = stack->elem->num;
	while (stack != NULL && stack->elem->tag == 0)
	{
		if (stack->elem->num < min)
			min = stack->elem->num;
		stack = stack->next;
	}
	return (min);
}
