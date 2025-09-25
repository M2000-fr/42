/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 18:04:24 by mechard           #+#    #+#             */
/*   Updated: 2023/08/07 21:33:33 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	add;

	add = 0;
	while (s1[add] != '\0' && add < n)
	{
		if (s1[add] != s2[add])
			return ((unsigned char)s1[add] - (unsigned char)s2[add]);
		add++;
	}
	if (s2[add] != '\0' && add < n)
		return ((unsigned char)s1[add] - (unsigned char)s2[add]);
	return (0);
}
