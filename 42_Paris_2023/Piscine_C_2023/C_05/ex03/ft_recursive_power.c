/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 14:55:27 by mechard           #+#    #+#             */
/*   Updated: 2023/08/10 23:00:49 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	int	s;

	s = 0;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb *= (ft_recursive_power(nb, power - 1)));
}

// int	main(void)
// {
// 	printf("rp de 0 = %d\n", ft_recursive_power(0, 5));
// 	printf("rp de 1 = %d\n", ft_recursive_power(1, 5));
// 	printf("rp de 2 = %d\n", ft_recursive_power(2, 5));
// 	printf("rp de 3 = %d\n", ft_recursive_power(3, 5));
// 	printf("rp de 4 = %d\n", ft_recursive_power(4, 5));
// 	printf("rp de 5 = %d\n", ft_recursive_power(5, 5));
// 	printf("rp de 6 = %d\n", ft_recursive_power(6, 5));
// 	printf("rp de 7 = %d\n", ft_recursive_power(7, 5));
// 	return (0);
// }
