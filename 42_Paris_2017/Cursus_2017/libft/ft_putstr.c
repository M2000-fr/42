/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:54:51 by maechard          #+#    #+#             */
/*   Updated: 2017/04/14 20:27:00 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr(char *str)
{
	int		adresse;

	if (!str)
		return ;
	adresse = 0;
	while (str[adresse] != '\0')
	{
		ft_putchar(str[adresse]);
		adresse++;
	}
}
