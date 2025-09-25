/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tabstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 06:08:39 by tarchen           #+#    #+#             */
/*   Updated: 2017/06/25 03:07:29 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int			ft_print_tabstr_fd(int size, char **tab, int endl, int fd)
{
	int 	i;

	i = -1;
	if (!tab)
		return (0);
	if (endl)
		while (++i < size)
			!tab[i] ? ft_putendl_fd("(null)", fd) : ft_putendl_fd(tab[i], fd);
	else
	{
		while (++i < size)
			!tab[i] ? ft_putstr_fd("(null) ", fd) : ft_putstr_fd(ft_strjoin(tab[i], " "), fd);
		ft_putchar_fd('\n', fd);
	}
	return (1);
}

int			ft_print_tabstr(int size, char **tab, int endl)
{
	int 	i;

	i = -1;
	if (!tab)
		return (0);
	if (endl)
		while (++i < size)
			!tab[i] ? ft_putendl("(null)") : ft_putendl(tab[i]);
	else
	{
		while (++i < size)
			!tab[i] ? ft_putstr("(null) ") : ft_putstr(ft_strjoin(tab[i], " "));
		ft_putchar('\n');
	}
	return (1);
}
