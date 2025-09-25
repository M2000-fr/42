/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:29:40 by mechard           #+#    #+#             */
/*   Updated: 2023/08/10 23:01:08 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (nb *= ft_recursive_factorial(nb - 1));
}

// int	main(void)
// {
// 	printf("rf de 0 = %d\n", ft_recursive_factorial(0));
// 	printf("rf de 1 = %d\n", ft_recursive_factorial(1));
// 	printf("rf de 2 = %d\n", ft_recursive_factorial(2));
// 	printf("rf de 3 = %d\n", ft_recursive_factorial(3));
// 	printf("rf de 4 = %d\n", ft_recursive_factorial(4));
// 	printf("rf de 5 = %d\n", ft_recursive_factorial(5));
// 	printf("rf de 6 = %d\n", ft_recursive_factorial(6));
// 	printf("rf de 7 = %d\n", ft_recursive_factorial(7));
// 	return (0);
// }
