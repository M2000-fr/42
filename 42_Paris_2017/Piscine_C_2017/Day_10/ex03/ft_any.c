/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/27 11:11:15 by maechard          #+#    #+#             */
/*   Updated: 2017/03/28 17:08:10 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_any(char **tab, int (*f)(char*))
{
	int		address;

	address = 0;
	while (tab[address] != 0)
	{
		if (f(tab[address]) == 1)
			return (1);
		address++;
	}
	return (0);
}
