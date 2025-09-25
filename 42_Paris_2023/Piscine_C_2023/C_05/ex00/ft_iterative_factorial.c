/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:31:59 by mechard           #+#    #+#             */
/*   Updated: 2023/08/10 23:01:13 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	a;
	int	i;

	a = 1;
	i = 1;
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		a *= i;
		nb--;
		i++;
	}
	return (a);
}

// int	main(void)
// {
// 	printf("if de 0 = %d\n", ft_iterative_factorial(0));
// 	printf("if de 1 = %d\n", ft_iterative_factorial(1));
// 	printf("if de 2 = %d\n", ft_iterative_factorial(2));
// 	printf("if de 3 = %d\n", ft_iterative_factorial(3));
// 	printf("if de 4 = %d\n", ft_iterative_factorial(4));
// 	printf("if de 5 = %d\n", ft_iterative_factorial(5));
// 	printf("if de 6 = %d\n", ft_iterative_factorial(6));
// 	printf("if de 7 = %d\n", ft_iterative_factorial(7));
// 	return (0);
// }
