/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:42:37 by maechard          #+#    #+#             */
/*   Updated: 2017/03/28 16:09:06 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		a;

	a = 0;
	while (tab[a] == tab[a + 1])
		a++;
	if (tab[a] < tab[a + 1])
		while (a + 1 < length)
		{
			if (f(tab[a], tab[a + 1]) > 0)
				return (0);
			a++;
		}
	if (tab[a] > tab[a + 1])
		while (a + 1 < length)
		{
			if (f(tab[a], tab[a + 1]) < 0)
				return (0);
			a++;
		}
	return (1);
}
