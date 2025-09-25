/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:27:01 by mechard           #+#    #+#             */
/*   Updated: 2024/04/19 18:02:42 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdbool.h>

typedef struct s_stack
{
	int				cost;
	int				nb;
	int				index;
	bool			cheap;
	bool			under_moyenne;
	struct s_stack	*next;
	struct s_stack	*closest;
}					t_stack;

int					ft_push_swap(int argc, char **argv);
int					is_sorted_stack(t_stack **stack);
int					stack_len(t_stack *stack);
int					ft_find_index(t_stack *stack, int nb);
int					error_repetition(t_stack *a, int nbr);
int					ft_stackadd_back(t_stack **stack, int nbr);

char				**ft_split_argv(const char *str, char charset);

void				ft_cost(t_stack *stack_1, t_stack *stack_2);
void				free_stack(t_stack **stack);
void				free_split(char **split);
void				error_free(t_stack **a, char **split, int flag);
void				sa(t_stack **stack_a);
void				sb(t_stack **stack_b);
void				ss(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				ra(t_stack **stack_a);
void				rb(t_stack **stack_b);
void				rr(t_stack **stack_a, t_stack **stack_b);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);
void				sort_three(t_stack **stack_a);
void				sort(t_stack **a, t_stack **b);
void				calculate_cost_a(t_stack **a, t_stack **b);
void				calculate_cost_b(t_stack **a, t_stack **b);
void				a_to_b(t_stack **a, t_stack **b);
void				b_to_a(t_stack **a, t_stack **b);
void				reverse_both(t_stack **stack_a, t_stack **stack_b,
						t_stack *cheap);
void				rotate_both(t_stack **stack_a, t_stack **stack_b,
						t_stack *cheap);
void				node_to_topa(t_stack **a, t_stack *node);
void				node_to_topb(t_stack **b, t_stack *node);
void				cost_a(t_stack *a, t_stack *b);
void				set_index(t_stack **a);
void				set_cheapest(t_stack **a);

t_stack				*ft_last(t_stack *stack);
t_stack				*ft_highest(t_stack *stack);
t_stack				*ft_lowest(t_stack *stack);
t_stack				*ft_cheapest(t_stack *stack);

#endif