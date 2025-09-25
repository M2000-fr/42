/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:44:12 by mechard           #+#    #+#             */
/*   Updated: 2024/03/26 18:45:08 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_cost(t_stack *stack_1, t_stack *stack_2)
{
	int	len1;
	int	len2;
	int	cost;

	len1 = stack_len(stack_1);
	len2 = stack_len(stack_2);
	while (stack_1)
	{
		cost = 0;
		if (ft_find_index(stack_1, stack_1->nb) > len1 / 2)
			cost += ft_find_index(stack_1, stack_1->nb);
		else
			cost += len1 - ft_find_index(stack_1, stack_1->nb);
		if (ft_find_index(stack_2, stack_1->closest->nb) > len2 / 2)
			cost += ft_find_index(stack_2, stack_1->closest->nb);
		else
			cost += len2 - ft_find_index(stack_2, stack_1->closest->nb);
		stack_1->cost = cost;
		stack_1 = stack_1->next;
	}
}

int	ft_find_index(t_stack *stack, int nb)
{
	int	i;

	i = 0;
	while (stack->nb != nb)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

t_stack	*ft_highest(t_stack *stack)
{
	t_stack	*highest;

	highest = stack;
	while (stack)
	{
		if (stack->nb > highest->nb)
			highest = stack;
		stack = stack->next;
	}
	return (highest);
}

t_stack	*ft_lowest(t_stack *stack)
{
	t_stack	*lowest;

	lowest = stack;
	while (stack)
	{
		if (stack->nb < lowest->nb)
			lowest = stack;
		stack = stack->next;
	}
	return (lowest);
}

t_stack	*ft_cheapest(t_stack *stack)
{
	while (stack)
	{
		if (stack->cheap)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
