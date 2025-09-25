/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:52:11 by mechard           #+#    #+#             */
/*   Updated: 2023/08/10 23:00:12 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>

int	ft_prime(int nb)
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

int	ft_find_next_prime(int nb)
{
	int	nb2;

	nb2 = nb;
	if (nb2 > 2147483639)
		return (0);
	while (ft_prime(nb2) < 1)
		nb2++;
	return (nb2);
}

// int	main(void)
// {
// 	int	nb;

// 	nb = 2147483475;
// 	while (nb <= 2147483500)
// 	{
// 		printf("ip de %d = %d\n", nb, ft_find_next_prime(nb));
// 		nb++;
// 	}
// 	return (0);
// }
