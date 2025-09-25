/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:01:17 by mechard           #+#    #+#             */
/*   Updated: 2023/08/10 23:00:43 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

// int	main(void)
// {
// 	printf("fib de 0 = %d\n", ft_fibonacci(0));
// 	printf("fib de 1 = %d\n", ft_fibonacci(1));
// 	printf("fib de 2 = %d\n", ft_fibonacci(2));
// 	printf("fib de 3 = %d\n", ft_fibonacci(3));
// 	printf("fib de 4 = %d\n", ft_fibonacci(4));
// 	printf("fib de 5 = %d\n", ft_fibonacci(5));
// 	printf("fib de 6 = %d\n", ft_fibonacci(6));
// 	printf("fib de 7 = %d\n", ft_fibonacci(7));
// 	return (0);
// }
