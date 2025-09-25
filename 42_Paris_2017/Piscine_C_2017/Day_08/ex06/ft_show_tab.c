/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 19:11:28 by maechard          #+#    #+#             */
/*   Updated: 2017/03/26 17:11:46 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <unistd.h>

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

void	ft_print_words_tables(char **tab)
{
	int		address;

	address = 0;
	if (tab != NULL)
	{
		while (tab[address] != 0)
		{
			ft_putstr(tab[address]);
			ft_putchar('\n');
			address++;
		}
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		ft_putstr("-2147483648");
	}
	else
	{
		if (nb < 0 && nb != -2147483648)
		{
			ft_putchar('-');
			nb = -nb;
		}
		if (nb <= 9)
		{
			ft_putchar(nb + 48);
		}
		if (nb >= 10)
		{
			ft_putnbr(nb / 10);
			ft_putchar(nb % 10 + 48);
		}
	}
}

void	ft_show_tab(struct s_stock_par *par)
{
	int		address;

	address = 0;
	while (par[address].str != 0)
	{
		ft_putstr(par[address].str);
		ft_putchar('\n');
		ft_putnbr(par[address].size_param);
		ft_putchar('\n');
		ft_print_words_tables(par[address].tab);
		address++;
	}
}
