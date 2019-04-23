/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtroll <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 16:00:53 by rtroll            #+#    #+#             */
/*   Updated: 2019/02/09 17:27:44 by rtroll           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef struct		s_data
{
	int				num;
	int				tag;
}					t_data;

typedef struct		s_stack
{
	t_data			*elem;
	struct s_stack	*next;
}					t_stack;

t_stack				*ft_create_elem(int data);
int					ft_check_str(char *str);
int					ft_check_command(char *tmp, char **line);
int					ft_print_error(t_stack **a, t_stack **b);
int					ft_dublicates(t_stack *stack);
int					ft_find_index(char *current, char **legit);
void				ft_ss(t_stack **a, t_stack **b);
void				ft_rr(t_stack **a, t_stack **b);
void				ft_rrr(t_stack **a, t_stack **b);
void				ft_push(t_stack **root, t_data *data);
t_data				*ft_pop(t_stack **root);
void				ft_sb(t_stack **a, t_stack **b);
void				ft_sa(t_stack **a, t_stack **b);
void				ft_rb(t_stack **a, t_stack **b);
void				ft_ra(t_stack **a, t_stack **b);
void				ft_execute(t_stack **a, t_stack **b, int index);
void				ft_pa(t_stack **a, t_stack **b);
void				ft_pb(t_stack **a, t_stack **b);
void				ft_rrb(t_stack **a, t_stack **b);
void				ft_rra(t_stack **a, t_stack **b);
void				ft_del_list(t_stack **root);
void				ft_clear_split(char **arr);
char				*ft_quick_sort(t_stack **a, t_stack **b);
void				ft_sa_ps(t_stack **a, t_stack **b, char **commands);
void				ft_sb_ps(t_stack **a, t_stack **b, char **commands);
void				ft_ra_ps(t_stack **a, t_stack **b, char **commands);
void				ft_rb_ps(t_stack **a, t_stack **b, char **commands);
void				ft_pa_ps(t_stack **a, t_stack **b, char **commands);
void				ft_pb_ps(t_stack **a, t_stack **b, char **commands);
void				ft_rra_ps(t_stack **a, t_stack **b, char **commands);
void				ft_rrb_ps(t_stack **a, t_stack **b, char **commands);
void				ft_sort_a(t_stack **a, t_stack **b, char **commands);
void				ft_sort_b(t_stack **a, t_stack **b, char **commands);
int					ft_abs(int number);
void				ft_sort_three_a(t_stack **a, t_stack **b, char **commands);
void				ft_insertion_b(t_stack **a, t_stack **b, char **commands);
void				ft_insertion_a(t_stack **a, t_stack **b, char **commands);
int					ft_find_way(t_stack *a, int p);
int					ft_is_tag_elem(t_stack *root);
int					ft_min(t_stack *stack);
int					ft_max(t_stack *stack);
void				ft_clear_split(char **arr);
void				ft_optimaze(char **ptr);
int					ft_get_commands(char **line);
int					ft_next_tag(t_stack *b);
int					ft_find_size(t_stack *a);
void				ft_bubble_sort(int *sorted, int size, int flag);

#endif
