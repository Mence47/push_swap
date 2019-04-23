/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 23:52:56 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/01 12:00:56 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_clear_split(char **arr)
{
	char **tmp;

	tmp = arr;
	while (*arr != NULL)
	{
		ft_strdel(arr);
		arr++;
	}
	free(tmp);
}

void	ft_pa(t_stack **a, t_stack **b)
{
	if (*b == NULL)
		return ;
	ft_push(a, ft_pop(b));
}

void	ft_pb(t_stack **a, t_stack **b)
{
	if (*a == NULL)
		return ;
	ft_push(b, ft_pop(a));
}

void	ft_rra(t_stack **a, t_stack **b)
{
	t_data	*tmp;
	t_stack	*root;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	root = *a;
	while (root->next->next != NULL)
		root = root->next;
	tmp = root->next->elem;
	free(root->next);
	root->next = NULL;
	ft_push(a, tmp);
	(void)b;
}

void	ft_rrb(t_stack **a, t_stack **b)
{
	t_data	*tmp;
	t_stack	*root;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	root = *b;
	while (root->next->next != NULL)
		root = root->next;
	tmp = root->next->elem;
	free(root->next);
	root->next = NULL;
	ft_push(b, tmp);
	(void)a;
}
