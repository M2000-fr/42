/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 22:05:54 by maechard          #+#    #+#             */
/*   Updated: 2017/03/15 21:29:47 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int		address;

	address = 0;
	while (str[address] != '\0')
	{
		if (str[address] < 65)
			return (0);
		if (str[address] > 90 && str[address] < 97)
			return (0);
		if (str[address] > 122)
			return (0);
		address++;
	}
	return (1);
}
