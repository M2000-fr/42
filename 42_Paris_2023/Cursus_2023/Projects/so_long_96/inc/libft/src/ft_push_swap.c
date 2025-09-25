/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:25:44 by mechard           #+#    #+#             */
/*   Updated: 2024/04/19 18:05:10 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_verif_argc(int argc, char **argv)
{
	if (argc == 1)
		return (0);
	else if (argc == 2 && !argv[1][0])
		return (ft_printf("Error\n"), 1);
	return (2);
}

void	ft_arg_to_stack(t_stack **stack, char **argv, int flag)
{
	long	nbr;
	int		i;

	i = 1;
	while (argv[i])
	{
		if (!ft_isnumeric(argv[i]))
			error_free(stack, argv, flag);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(stack, argv, flag);
		if (error_repetition(*stack, (int)nbr))
			error_free(stack, argv, flag);
		if (ft_stackadd_back(stack, (int)nbr) == 1)
			error_free(stack, argv, flag);
		++i;
	}
	if (flag)
		free_split(argv);
}

int	ft_push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (ft_verif_argc(argc, argv));
	else if (argc == 2)
		argv = ft_split_argv(argv[1], ' ');
	if (!argv)
		return (0);
	ft_arg_to_stack(&stack_a, argv, argc == 2);
	stack_b = NULL;
	if (!is_sorted_stack(&stack_a))
	{
		if (stack_len(stack_a) == 2)
			sa(&stack_a);
		else if (stack_len(stack_a) == 3)
			sort_three(&stack_a);
		else
			sort(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
