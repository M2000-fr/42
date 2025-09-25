/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:54:27 by mechard           #+#    #+#             */
/*   Updated: 2023/08/07 21:39:27 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	add;
	unsigned int	add2;

	add = 0;
	add2 = 0;
	while (src[add] != '\0')
		add++;
	if (size == 0)
		return (add);
	add = 0;
	while (dest[add] != '\0')
		add++;
	while (src[add2] != '\0' && add2 < size)
	{
		dest[add + add2] = src[add2];
		add2++;
	}
	if (add2 < size)
		dest[add + add2] = '\0';
	return (add + add2);
}
