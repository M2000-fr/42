/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 20:41:43 by maechard          #+#    #+#             */
/*   Updated: 2017/04/14 20:43:09 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	int		adresse;

	if (!str)
		return ;
	adresse = 0;
	while (str[adresse] != '\0')
	{
		ft_putchar_fd(str[adresse], fd);
		adresse++;
	}
}
