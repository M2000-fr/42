/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:30:32 by mechard           #+#    #+#             */
/*   Updated: 2024/04/09 15:31:20 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheap)
{
	while (*stack_a != cheap && *stack_b != cheap->closest)
		rrr(stack_a, stack_b);
	set_index(stack_a);
	set_index(stack_b);
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b, t_stack *cheap)
{
	while (*stack_a != cheap && *stack_b != cheap->closest)
		rr(stack_a, stack_b);
	set_index(stack_a);
	set_index(stack_b);
}

void	node_to_topa(t_stack **a, t_stack *node)
{
	while (*a != node)
	{
		if (node->under_moyenne)
			ra(a);
		else
			rra(a);
	}
}

void	node_to_topb(t_stack **b, t_stack *node)
{
	while (*b != node)
	{
		if (node->under_moyenne)
			rb(b);
		else
			rrb(b);
	}
}

void	a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheap;

	cheap = ft_cheapest(*a);
	if (cheap->under_moyenne && cheap->closest->under_moyenne)
		rotate_both(a, b, cheap);
	else if (!cheap->under_moyenne && !cheap->closest->under_moyenne)
		reverse_both(a, b, cheap);
	node_to_topa(a, cheap);
	node_to_topb(b, cheap->closest);
	pb(a, b);
}
