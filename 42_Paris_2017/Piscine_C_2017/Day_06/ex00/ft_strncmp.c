/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 18:27:17 by maechard          #+#    #+#             */
/*   Updated: 2017/03/15 12:37:58 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	address;

	address = 0;
	while (s1[address] != '\0' && address < n)
	{
		if (s1[address] != s2[address])
			return (s1[address] - s2[address]);
		address++;
	}
	if (s2[address] != '\0' && address < n)
		return (s1[address] - s2[address]);
	return (0);
}
