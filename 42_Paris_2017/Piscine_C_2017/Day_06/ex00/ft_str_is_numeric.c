/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 11:45:02 by maechard          #+#    #+#             */
/*   Updated: 2017/03/15 15:49:46 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_numeric(char *str)
{
	int		address;

	address = 0;
	while (str[address] != '\0')
	{
		if (str[address] > 47 && str[address] < 58)
			address++;
		else
			return (0);
	}
	return (1);
}
