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

static void	ft_push_max(t_stack **a, t_stack **b, char **commands)
{
	int	steps_down;
	int	steps_up;
	int	max;

	steps_down = 1;
	steps_up = 1;
	max = ft_max(*b);
	while ((*b)->elem->num != max)
	{
		if (ft_find_way(*b, max) == 1)
		{
			ft_rrb_ps(a, b, commands);
			steps_down++;
		}
		else
		{
			ft_rb_ps(a, b, commands);
			steps_up++;
		}
	}
	ft_pa_ps(a, b, commands);
	while (--steps_down > 1 && ft_is_tag_elem(*b) == 1)
		ft_rb_ps(a, b, commands);
	while (--steps_up > 0 && ft_is_tag_elem(*b) == 1)
		ft_rrb_ps(a, b, commands);
}

void		ft_insertion_b(t_stack **a, t_stack **b, char **commands)
{
	int		i;
	t_stack	*tmp;

	i = ft_find_size(*b);
	while (ft_find_size(*b) > 0)
		ft_push_max(a, b, commands);
	while (i-- > 0)
		ft_pb_ps(a, b, commands);
	tmp = *b;
	while (tmp != NULL && tmp->elem->tag == 0)
	{
		tmp->elem->tag = 1;
		tmp = tmp->next;
	}
}
