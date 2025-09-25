/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tabint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 08:03:25 by tarchen           #+#    #+#             */
/*   Updated: 2017/01/23 08:23:27 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int				ft_print_tabint(int size_tab, int *tab, int endl)
{
	int			i;

	i = 0;
	if (!tab)
		return (0);
	if (!endl)
		while (i < size_tab)
		{
			ft_putnbr(tab[i]);
			ft_putchar(' ');
			i++;
		}
	else
		while (i < size_tab)
		{
			if (i)
				ft_putchar('\n');
			ft_putnbr(tab[i]);
			i++;
		}
	ft_putchar('\n');
	return (1);
}
