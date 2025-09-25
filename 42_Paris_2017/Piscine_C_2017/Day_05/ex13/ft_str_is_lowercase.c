/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:48:07 by maechard          #+#    #+#             */
/*   Updated: 2017/03/16 15:18:22 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	int		address;

	address = 0;
	while (str[address] != '\0')
	{
		if (str[address] < 97 || str[address] > 122)
			return (0);
		address++;
	}
	return (1);
}
