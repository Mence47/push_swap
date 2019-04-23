/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_seven.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:54:29 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/09 17:27:44 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

static void	ft_push_min(t_stack **a, t_stack **b, char **commands)
{
	int steps_up;
	int steps_down;
	int min;

	steps_up = 1;
	steps_down = 1;
	min = ft_min(*a);
	while ((*a)->elem->num != min)
	{
		if (ft_find_way(*a, min) == 1)
		{
			ft_rra_ps(a, b, commands);
			steps_down++;
		}
		else
		{
			ft_ra_ps(a, b, commands);
			steps_up++;
		}
	}
	ft_pb_ps(a, b, commands);
	while (--steps_down > 1 && ft_is_tag_elem(*a) == 1)
		ft_ra_ps(a, b, commands);
	while (--steps_up > 0 && ft_is_tag_elem(*a) == 1)
		ft_rra_ps(a, b, commands);
}

void		ft_insertion_a(t_stack **a, t_stack **b, char **commands)
{
	int		i;
	t_stack	*tmp;

	i = ft_find_size(*a);
	while (ft_find_size(*a) > 0)
		ft_push_min(a, b, commands);
	while (i-- > 0)
		ft_pa_ps(a, b, commands);
	tmp = *a;
	while (tmp != NULL && tmp->elem->tag == 0)
	{
		tmp->elem->tag = 1;
		tmp = tmp->next;
	}
}
