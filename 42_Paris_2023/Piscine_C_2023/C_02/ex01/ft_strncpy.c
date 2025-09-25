/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:14:29 by mechard           #+#    #+#             */
/*   Updated: 2023/08/07 11:28:46 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	add;

	add = 0;
	while (src[add] != '\0' && add < n)
	{
		dest[add] = src[add];
		add++;
	}
	while (add < n)
	{
		dest[add] = '\0';
		add++;
	}
	return (dest);
}
