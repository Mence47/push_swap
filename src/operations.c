/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 22:53:23 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/01 12:00:56 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int		ft_find_index(char *current, char **legit)
{
	int index;

	index = 0;
	while (index < 11)
	{
		if (ft_strcmp(current, legit[index]) == 0)
			break ;
		index++;
	}
	return (index);
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a, b);
	ft_sb(a, b);
}

void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a, b);
	ft_rb(a, b);
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rra(a, b);
	ft_rrb(a, b);
}

void	ft_execute(t_stack **a, t_stack **b, int index)
{
	void	(*f[11])(t_stack**, t_stack**);

	f[0] = ft_sa;
	f[1] = ft_sb;
	f[2] = ft_ss;
	f[3] = ft_pa;
	f[4] = ft_pb;
	f[5] = ft_ra;
	f[6] = ft_rb;
	f[7] = ft_rr;
	f[8] = ft_rra;
	f[9] = ft_rrb;
	f[10] = ft_rrr;
	f[index](a, b);
}
