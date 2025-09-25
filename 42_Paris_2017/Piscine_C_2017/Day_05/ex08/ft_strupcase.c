/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:33:16 by maechard          #+#    #+#             */
/*   Updated: 2017/03/15 12:42:32 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strupcase(char *str)
{
	int	address;

	address = 0;
	while (str[address] != '\0')
	{
		if (str[address] > 96 && str[address] < 123)
			str[address] = str[address] - 32;
		address++;
	}
	return (str);
}
