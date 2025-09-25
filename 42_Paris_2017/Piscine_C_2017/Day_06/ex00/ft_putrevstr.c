/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putrevstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:54:51 by maechard          #+#    #+#             */
/*   Updated: 2017/03/15 20:19:27 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_putrevstr(char *str)
{
	int		address;

	address = 0;
	while (str[address] != '\0')
		address++;
	while (address != -1)
	{
		ft_putchar(str[address]);
		address--;
	}
}
