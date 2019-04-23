/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:50:16 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/01 12:00:56 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_pa_ps(t_stack **a, t_stack **b, char **commands)
{
	char *new;

	if (*b == NULL)
		return ;
	ft_push(a, ft_pop(b));
	new = ft_strjoin(*commands, **commands == '\0' ? "pa" : "\npa");
	ft_strdel(commands);
	*commands = new;
}

void	ft_pb_ps(t_stack **a, t_stack **b, char **commands)
{
	char *new;

	if (*a == NULL)
		return ;
	ft_push(b, ft_pop(a));
	new = ft_strjoin(*commands, **commands == '\0' ? "pb" : "\npb");
	ft_strdel(commands);
	*commands = new;
}

void	ft_rra_ps(t_stack **a, t_stack **b, char **commands)
{
	t_data	*tmp;
	t_stack	*root;
	char	*new;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	root = *a;
	while (root->next->next != NULL)
		root = root->next;
	tmp = root->next->elem;
	free(root->next);
	root->next = NULL;
	ft_push(a, tmp);
	new = ft_strjoin(*commands, **commands == '\0' ? "rra" : "\nrra");
	ft_strdel(commands);
	*commands = new;
	(void)b;
}

void	ft_rrb_ps(t_stack **a, t_stack **b, char **commands)
{
	t_data	*tmp;
	t_stack	*root;
	char	*new;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	root = *b;
	while (root->next->next != NULL)
		root = root->next;
	tmp = root->next->elem;
	free(root->next);
	root->next = NULL;
	ft_push(b, tmp);
	new = ft_strjoin(*commands, **commands == '\0' ? "rrb" : "\nrrb");
	ft_strdel(commands);
	*commands = new;
	(void)a;
}
