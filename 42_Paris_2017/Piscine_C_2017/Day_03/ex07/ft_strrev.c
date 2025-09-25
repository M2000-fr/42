/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 14:09:46 by maechard          #+#    #+#             */
/*   Updated: 2017/03/11 22:13:08 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		lenght;
	int		address;
	int		tmp;

	lenght = 0;
	address = 0;
	while (str[lenght] != '\0')
		lenght++;
	lenght--;
	while (address < lenght)
	{
		tmp = str[address];
		str[address] = str[lenght];
		str[lenght] = tmp;
		lenght--;
		address++;
	}
	return (str);
}
