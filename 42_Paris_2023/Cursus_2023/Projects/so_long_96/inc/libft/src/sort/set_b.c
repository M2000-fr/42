/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_b.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:30:50 by mechard           #+#    #+#             */
/*   Updated: 2024/03/26 18:32:14 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	cost_b(t_stack *a, t_stack *b)
{
	t_stack		*target;
	t_stack		*current_a;
	long int	best;

	while (b)
	{
		best = LONG_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nb < best && current_a->nb > b->nb)
			{
				best = current_a->nb;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best == LONG_MAX)
			b->closest = ft_lowest(a);
		else
			b->closest = target;
		b = b->next;
	}
}

void	b_to_a(t_stack **a, t_stack **b)
{
	t_stack	*target;

	set_index(a);
	set_index(b);
	cost_b(*a, *b);
	target = (*b)->closest;
	node_to_topa(a, target);
	pa(a, b);
}
