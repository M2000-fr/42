/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:51:40 by mechard           #+#    #+#             */
/*   Updated: 2023/08/10 23:00:56 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	a;

	a = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		a *= nb;
		power--;
	}
	return (a);
}

// int	main(void)
// {
// 	printf("ip de 0 = %d\n", ft_iterative_power(0, 5));
// 	printf("ip de 1 = %d\n", ft_iterative_power(1, 5));
// 	printf("ip de 2 = %d\n", ft_iterative_power(2, 5));
// 	printf("ip de 3 = %d\n", ft_iterative_power(3, 5));
// 	printf("ip de 4 = %d\n", ft_iterative_power(4, 5));
// 	printf("ip de 5 = %d\n", ft_iterative_power(5, 5));
// 	printf("ip de 6 = %d\n", ft_iterative_power(6, 5));
// 	printf("ip de 7 = %d\n", ft_iterative_power(7, 5));
// 	return (0);
// }
