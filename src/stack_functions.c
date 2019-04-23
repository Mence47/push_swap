/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:54:44 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/01 12:00:56 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_stack	*ft_create_elem(int data)
{
	t_stack	*elem;

	elem = (t_stack*)malloc(sizeof(t_stack));
	elem->elem = (t_data*)malloc(sizeof(t_data));
	elem->elem->num = data;
	elem->elem->tag = 0;
	elem->next = NULL;
	return (elem);
}

void	ft_del_list(t_stack **root)
{
	if (root == NULL || *root == NULL)
		return ;
	free(ft_pop(root));
	ft_del_list(root);
}

t_data	*ft_pop(t_stack **root)
{
	t_stack	*tmp;
	t_data	*data;

	if (root == NULL || *root == NULL)
		return (NULL);
	tmp = *root;
	data = tmp->elem;
	*root = (*root)->next;
	free(tmp);
	return (data);
}

void	ft_push(t_stack **root, t_data *data)
{
	t_stack *new;

	new = ft_create_elem(data->num);
	new->elem->tag = data->tag;
	free(data);
	new->next = *root;
	*root = new;
}
