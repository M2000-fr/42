/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:44:09 by mechard           #+#    #+#             */
/*   Updated: 2024/04/22 12:26:19 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_last(t_stack *stack)
{
	if (stack == NULL)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	ft_stackadd_back(t_stack **stack, int nbr)
{
	t_stack	*new;
	t_stack	*last;

	if (stack == NULL)
		return (1);
	new = malloc(sizeof(t_stack));
	if (!new)
		return (1);
	new->nb = nbr;
	new->next = NULL;
	if (!*stack)
		*stack = new;
	else
	{
		last = ft_last(*stack);
		last->next = new;
	}
	return (0);
}

int	stack_len(t_stack *stack)
{
	int		len;
	t_stack	*tmp;

	len = 0;
	tmp = stack;
	while (tmp)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

int	is_sorted_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
