/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:54:51 by maechard          #+#    #+#             */
/*   Updated: 2017/03/18 22:17:36 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putstr(char *str)
{
	int		adresse;

	adresse = 0;
	while (str[adresse] != '\0')
	{
		ft_putchar(str[adresse]);
		adresse++;
	}
}
