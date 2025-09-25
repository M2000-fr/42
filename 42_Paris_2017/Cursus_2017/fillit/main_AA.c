/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_AA.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 18:57:29 by maechard          #+#    #+#             */
/*   Updated: 2017/04/28 18:57:41 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		main(int ac, char **av)
{
	int		fd;
	int		nbps;
	int		res;
	char	str[4096];
	char	**tab;

	nbps = 0;
	if (ac != 2)
		return (0);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		return (0);
	if ((res = read(fd, str, 4096)) == -1)
		return (0);
	tab = ft_tetriontab(str, tab);
	if ((res = ft_verif(tab)) == 1)
		return (0);
	tab = ft_transform(tab);
	ft_print_words_tables(tab);
	if (close(fd) == -1)
		return (0);
	return (0);
}
