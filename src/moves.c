/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:28:06 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/01 12:00:56 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_sa(t_stack **a, t_stack **b)
{
	t_data	*tmp;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = (*a)->elem;
	(*a)->elem = (*a)->next->elem;
	(*a)->next->elem = tmp;
	(void)b;
}

void	ft_sb(t_stack **a, t_stack **b)
{
	t_data	*tmp;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	tmp = (*b)->elem;
	(*b)->elem = (*b)->next->elem;
	(*b)->next->elem = tmp;
	(void)a;
}

void	ft_ra(t_stack **a, t_stack **b)
{
	t_data	*tmp;
	t_stack	*root;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = ft_pop(a);
	root = *a;
	while (root->next != NULL)
		root = root->next;
	root->next = ft_create_elem(tmp->num);
	root->elem->tag = tmp->tag;
	free(tmp);
	(void)b;
}

void	ft_rb(t_stack **a, t_stack **b)
{
	t_data	*tmp;
	t_stack	*root;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	tmp = ft_pop(b);
	root = *b;
	while (root->next != NULL)
		root = root->next;
	root->next = ft_create_elem(tmp->num);
	root->elem->tag = tmp->tag;
	free(tmp);
	(void)a;
}
