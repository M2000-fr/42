/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:50:23 by maechard          #+#    #+#             */
/*   Updated: 2017/03/16 12:41:38 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_uppercase(char *str)
{
	int		address;

	address = 0;
	while (str[address] != '\0')
	{
		if (str[address] > 64 && str[address] < 91)
			address++;
		else
			return (0);
	}
	return (1);
}
