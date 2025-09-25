/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:41:03 by maechard          #+#    #+#             */
/*   Updated: 2017/03/14 18:44:56 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	address;

	address = 0;
	while (str[address] != '\0')
	{
		if (str[address] < 91 && str[address] > 64)
			str[address] = str[address] + 32;
		address++;
	}
	return (str);
}
