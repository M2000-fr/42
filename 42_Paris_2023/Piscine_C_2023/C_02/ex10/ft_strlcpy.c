/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 21:45:03 by mechard           #+#    #+#             */
/*   Updated: 2023/08/06 19:56:39 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	add;
	unsigned int	len;

	add = 0;
	len = 0;
	while (src[len] != '\0')
		len++;
	while (src[add] != '\0' && add < size)
	{
		dest[add] = src[add];
		add++;
	}
	dest[add] = '\0';
	return (len);
}
