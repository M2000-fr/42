/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:12:15 by mechard           #+#    #+#             */
/*   Updated: 2023/08/10 23:00:21 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_is_prime(int nb)
{
	int	a;

	if (nb <= 1)
		return (0);
	if (nb == 2 || nb == 3)
		return (1);
	if (nb % 2 == 0 || nb % 3 == 0)
		return (0);
	a = 3;
	while ((a * a) <= nb)
	{
		if ((nb % a) == 0)
			return (0);
		a += 2;
	}
	return (1);
}

// int	main(void)
// {
// 	int	nb;

// 	nb = 2147483620;
// 	while (nb <= 2147483646)
// 	{
// 		if (ft_is_prime(nb) == 1 && nb <= 2147483647)
// 			printf("ip de %d = %d\n", nb, ft_is_prime(nb));
// 		nb++;
// 	}
// 	return (0);
// }
