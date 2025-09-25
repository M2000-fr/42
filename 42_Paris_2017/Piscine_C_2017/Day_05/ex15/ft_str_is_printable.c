/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:59:40 by maechard          #+#    #+#             */
/*   Updated: 2017/03/15 16:08:51 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int		address;

	address = 0;
	while (str[address] != '\0')
	{
		if (str[address] > 32 && str[address] != 127)
			address++;
		else
			return (0);
	}
	return (1);
}
