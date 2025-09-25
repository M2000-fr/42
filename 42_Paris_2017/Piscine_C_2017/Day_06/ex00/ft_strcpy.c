/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 14:23:02 by maechard          #+#    #+#             */
/*   Updated: 2017/03/15 14:17:54 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int		address;

	address = 0;
	while (src[address] != '\0')
	{
		dest[address] = src[address];
		address++;
	}
	dest[address] = '\0';
	return (dest);
}
