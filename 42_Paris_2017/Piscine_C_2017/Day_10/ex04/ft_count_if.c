/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:17:25 by maechard          #+#    #+#             */
/*   Updated: 2017/03/28 17:07:51 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char*))
{
	int		address;
	int		nb;

	nb = 0;
	address = 0;
	while (tab[address] != 0)
	{
		if (f(tab[address]) == 1)
			nb++;
		address++;
	}
	return (nb);
}
