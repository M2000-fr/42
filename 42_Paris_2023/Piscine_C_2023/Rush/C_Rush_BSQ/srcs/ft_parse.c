/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:00:16 by mechard           #+#    #+#             */
/*   Updated: 2023/08/23 21:04:19 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_strcat(char *str1, char *str2)
{
	int		add;
	int		add2;
	char	*map;

	add = ft_strlen(str1);
	add2 = 0;
	map = (char *)malloc(sizeof(char) * (add + ft_strlen(str2)) + 1);
	if (!map)
		return (0);
	while (str1[add2])
	{
		map[add2] = str1[add2];
		add2++;
	}
	add2 = 0;
	while (str2[add2] != '\0')
	{
		map[add + add2] = str2[add2];
		add2++;
	}
	map[add + add2] = '\0';
	return (map);
}

char	*ft_strmap(int fd, t_args *arg)
{
	char	*map;
	char	*str;

	map = ft_reader(fd);
	str = ft_reader(fd);
	arg->len = ft_count_len(str);
	while (str)
	{
		map = ft_strcat(map, str);
		str = ft_reader(fd);
	}
	return (map);
}

void	ft_split_args(t_args *arg, char *str)
{
	arg->remp = str[ft_strlen(str) - 2];
	arg->obst = str[ft_strlen(str) - 3];
	arg->vide = str[ft_strlen(str) - 4];
}

char	**ft_dd_map(t_args *arg, char *str)
{
	char	**dest;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	dest = malloc(sizeof(char *) * ft_count_line(str));
	while (str[i] && k < arg->nb_line)
	{
		j = 0;
		dest[k] = malloc(sizeof(char) * (arg->len));
		if (arg->len > 0)
		{
			while (j < arg->len - 1 && (str[i] == arg->obst || str[i] == arg->vide))
				dest[k][j++] = str[i++];
			dest[k++][j] = '\0';
			if (j != arg->len - 1)
				return(free(dest), NULL);
		}
		if (str[i] == '\0' || str[i] == '\n')
			i++;
	}
	dest[k] = NULL;
	return (dest);
}

char	**ft_split_map(t_args *arg, int fd)
{
	int		i;
	char	*src;
	char	**map;

	i = 0;
	src = ft_reader(fd);
	ft_split_args(arg, src);
	src = ft_strmap(fd, arg);
	ft_count(arg, src);
	map = ft_dd_map(arg, src);
	return (map);
}
