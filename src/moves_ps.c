/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_ps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 16:49:47 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/01 12:00:56 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	ft_sa_ps(t_stack **a, t_stack **b, char **commands)
{
	t_data	*tmp;
	char	*new;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = (*a)->elem;
	(*a)->elem = (*a)->next->elem;
	(*a)->next->elem = tmp;
	new = ft_strjoin(*commands, **commands == '\0' ? "sa" : "\nsa");
	ft_strdel(commands);
	*commands = new;
	(void)b;
}

void	ft_sb_ps(t_stack **a, t_stack **b, char **commands)
{
	t_data	*tmp;
	char	*new;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	tmp = (*b)->elem;
	(*b)->elem = (*b)->next->elem;
	(*b)->next->elem = tmp;
	new = ft_strjoin(*commands, **commands == '\0' ? "sb" : "\nsb");
	ft_strdel(commands);
	*commands = new;
	(void)a;
}

void	ft_ra_ps(t_stack **a, t_stack **b, char **commands)
{
	t_data	*tmp;
	t_stack	*root;
	char	*new;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = ft_pop(a);
	root = *a;
	while (root->next != NULL)
		root = root->next;
	root->next = ft_create_elem(tmp->num);
	root->next->elem->tag = tmp->tag;
	free(tmp);
	new = ft_strjoin(*commands, **commands == '\0' ? "ra" : "\nra");
	ft_strdel(commands);
	*commands = new;
	(void)b;
}

void	ft_rb_ps(t_stack **a, t_stack **b, char **commands)
{
	t_data	*tmp;
	t_stack	*root;
	char	*new;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	tmp = ft_pop(b);
	root = *b;
	while (root->next != NULL)
		root = root->next;
	root->next = ft_create_elem(tmp->num);
	root->next->elem->tag = tmp->tag;
	free(tmp);
	new = ft_strjoin(*commands, **commands == '\0' ? "rb" : "\nrb");
	ft_strdel(commands);
	*commands = new;
	(void)a;
}
