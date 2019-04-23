/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 21:26:38 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/09 17:27:44 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void		ft_bubble_sort(int *sorted, int size, int flag)
{
	int i;
	int j;
	int tmp;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size - 1)
		{
			if (sorted[j] < sorted[j + 1] && flag == -1)
			{
				tmp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = tmp;
			}
			else if (sorted[j] > sorted[j + 1] && flag == 1)
			{
				tmp = sorted[j];
				sorted[j] = sorted[j + 1];
				sorted[j + 1] = tmp;
			}
		}
	}
}

static int	ft_is_sorted(t_stack **a)
{
	t_stack	*root;

	root = *a;
	while (root->next != NULL && root->elem->tag == 0)
	{
		if (root->elem->num > root->next->elem->num)
			return (0);
		root = root->next;
	}
	return (1);
}

void		ft_sort_three_a(t_stack **a, t_stack **b, char **commands)
{
	if (ft_is_sorted(a) == 1)
		;
	else if (ft_find_size(*a) == 2)
		ft_sa_ps(a, b, commands);
	else if ((*a)->elem->num == ft_min(*a))
	{
		ft_sa_ps(a, b, commands);
		ft_ra_ps(a, b, commands);
	}
	else if ((*a)->elem->num == ft_max(*a))
	{
		ft_ra_ps(a, b, commands);
		ft_sort_three_a(a, b, commands);
	}
	else
	{
		ft_sa_ps(a, b, commands);
		ft_sort_three_a(a, b, commands);
	}
}
