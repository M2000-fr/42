/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:17:28 by mechard           #+#    #+#             */
/*   Updated: 2023/08/07 21:36:50 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	add;
	unsigned int	add2;

	add = 0;
	add2 = 0;
	while (dest[add] != '\0')
		add++;
	while (src[add2] != '\0' && add2 < nb)
	{
		dest[add + add2] = src[add2];
		add2++;
	}
	dest[add + add2] = '\0';
	return (dest);
}
