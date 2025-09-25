/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 17:56:25 by maechard          #+#    #+#             */
/*   Updated: 2017/03/15 12:33:39 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(char *s1, char *s2)
{
	int		address;

	address = 0;
	while (s1[address] != '\0')
	{
		if (s1[address] != s2[address])
			return (s1[address] - s2[address]);
		address++;
	}
	if (s2[address] != '\0')
		return (s1[address] - s2[address]);
	return (0);
}
