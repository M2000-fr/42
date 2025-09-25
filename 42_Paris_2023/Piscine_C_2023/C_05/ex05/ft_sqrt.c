/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:05:37 by mechard           #+#    #+#             */
/*   Updated: 2023/08/10 23:00:37 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_sqrt(int nb)
{
	int	a;

	a = 1;
	if (nb <= 0)
		return (0);
	while (a < 46342)
	{
		if ((a * a) == nb)
			return (a);
		a++;
	}
	return (0);
}

// int	main(void)
// {
// 	printf("sqrt de 0 = %d\n", ft_sqrt(0));
// 	printf("sqrt de 1 = %d\n", ft_sqrt(1));
// 	printf("sqrt de 2 = %d\n", ft_sqrt(2));
// 	printf("sqrt de 4 = %d\n", ft_sqrt(4));
// 	printf("sqrt de 9 = %d\n", ft_sqrt(9));
// 	printf("sqrt de 16 = %d\n", ft_sqrt(16));
// 	printf("sqrt de 25 = %d\n", ft_sqrt(25));
// 	printf("sqrt de 36 = %d\n", ft_sqrt(36));
// 	return (0);
// }
