/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 18:31:54 by maechard          #+#    #+#             */
/*   Updated: 2017/03/28 20:38:15 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_par.h"

int						ft_strlen(char *str)
{
	int		lenght;

	lenght = 0;
	while (str[lenght] != '\0')
		lenght++;
	return (lenght);
}

char					*ft_strdup(char *src)
{
	int		address;
	char	*dest;

	address = 0;
	while (src[address] != '\0')
		address++;
	dest = malloc(sizeof(char) * (address + 1));
	if (dest == NULL)
		return (NULL);
	address = 0;
	while (src[address] != '\0')
	{
		dest[address] = src[address];
		address++;
	}
	dest[address] = '\0';
	return (dest);
}

struct	s_stock_par		*ft_param_to_tab(int ac, char **av)
{
	t_stock_par		*param;
	int				a;

	if (!(param = (t_stock_par*)malloc(sizeof(*param) * ac)))
		return (NULL);
	a = 0;
	while (a < ac)
	{
		param[a].size_param = ft_strlen(av[a]);
		param[a].str = av[a];
		param[a].copy = ft_strdup(av[a]);
		param[a].tab = ft_split_whitespaces(av[a]);
		a++;
	}
	(param + ac)->str = 0;
	return (param);
}
