/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 12:28:18 by mechard           #+#    #+#             */
/*   Updated: 2023/08/21 13:29:56 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	add;

	add = 0;
	while (s1[add] != '\0')
	{
		if (s1[add] != s2[add])
			return ((unsigned char)s1[add] - (unsigned char)s2[add]);
		add++;
	}
	if (s2[add] != '\0')
		return ((unsigned char)s1[add] - (unsigned char)s2[add]);
	return (0);
}
