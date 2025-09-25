/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:31:10 by mechard           #+#    #+#             */
/*   Updated: 2024/03/26 18:32:11 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack_a)
{
	t_stack	*highest;

	highest = ft_highest(*stack_a);
	if (highest == *stack_a)
		ra(stack_a);
	else if (highest == (*stack_a)->next)
		rra(stack_a);
	if ((*stack_a)->nb > (*stack_a)->next->nb)
		sa(stack_a);
}

void	sort(t_stack **a, t_stack **b)
{
	if (!is_sorted_stack(a) && stack_len(*a) > 3)
		pb(a, b);
	if (!is_sorted_stack(a) && stack_len(*a) > 3)
		pb(a, b);
	while (stack_len(*a) > 3 && !is_sorted_stack(a))
	{
		calculate_cost_a(a, b);
		a_to_b(a, b);
	}
	sort_three(a);
	while (*b)
		b_to_a(a, b);
	set_index(a);
	node_to_topa(a, ft_lowest(*a));
}
