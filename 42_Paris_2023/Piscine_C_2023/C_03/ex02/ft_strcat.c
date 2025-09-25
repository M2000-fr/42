/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:11:01 by mechard           #+#    #+#             */
/*   Updated: 2023/08/08 10:00:08 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *dest, char *src)
{
	int	add;
	int	add2;

	add = 0;
	add2 = 0;
	while (dest[add] != '\0')
		add++;
	while (src[add2] != '\0')
	{
		dest[add + add2] = src[add2];
		add2++;
	}
	dest[add + add2] = '\0';
	return (dest);
}
