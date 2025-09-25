/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_a.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:29:47 by mechard           #+#    #+#             */
/*   Updated: 2024/03/26 18:32:18 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_index(t_stack **a)
{
	t_stack	*tmp;
	int		i;
	int		len;

	i = 0;
	tmp = *a;
	len = stack_len(*a);
	while (tmp)
	{
		tmp->index = i;
		tmp->cheap = false;
		if (i > len / 2)
			tmp->under_moyenne = false;
		else
			tmp->under_moyenne = true;
		tmp = tmp->next;
		i++;
	}
}

void	cost_a(t_stack *a, t_stack *b)
{
	t_stack		*target;
	t_stack		*current_b;
	long int	best;

	while (a)
	{
		best = LONG_MIN;
		current_b = b;
		while (current_b)
		{
			if (current_b->nb > best && current_b->nb < a->nb)
			{
				best = current_b->nb;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best == LONG_MIN)
			a->closest = ft_highest(b);
		else
			a->closest = target;
		a = a->next;
	}
	ft_cost(a, b);
}

void	set_cheapest(t_stack **a)
{
	t_stack		*tmp;
	t_stack		*cheapest;
	long int	cost;

	cost = LONG_MAX;
	tmp = *a;
	while (tmp)
	{
		if (tmp->cost < cost)
		{
			cheapest = tmp;
			cost = tmp->cost;
		}
		tmp = tmp->next;
	}
	cheapest->cheap = true;
}

void	set_cost_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	int		cost;
	int		len1;
	int		len2;

	len1 = stack_len(*a);
	len2 = stack_len(*b);
	tmp = *a;
	while (tmp)
	{
		cost = tmp->index;
		if (!tmp->under_moyenne)
			cost = len1 - tmp->index;
		if (tmp->closest->under_moyenne)
			cost += tmp->closest->index;
		else
			cost += len2 - tmp->closest->index;
		tmp->cost = cost;
		tmp = tmp->next;
	}
}

void	calculate_cost_a(t_stack **a, t_stack **b)
{
	set_index(a);
	set_index(b);
	cost_a(*a, *b);
	set_cost_a(a, b);
	set_cheapest(a);
}
