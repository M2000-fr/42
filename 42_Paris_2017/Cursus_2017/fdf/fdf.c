/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 03:47:36 by maechard          #+#    #+#             */
/*   Updated: 2024/02/01 12:51:57 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct		s_tmp
{
	int				*tab;
	struct s_tmp	*next;
}					t_tmp;

void		fdf(char	*map)
{
	int		**quadr;
	char	**split;
	t_all	*all;
	t_zoom	*loupe;
	char	*str;
	int		fd;
	int		i;

	int		bite;

	t_tmp	*tab;
	t_tmp	*tmp;
	t_tmp	*new;

	str = try_malloc(1, _FL_);
	all = try_malloc(sizeof(t_all), _FL_);
	loupe = try_malloc(sizeof(t_zoom), _FL_);
	str = "1";
	loupe->logr = 50;
	loupe->lagr = 50;
	loupe->win_x = 500;
	loupe->win_y = 500;
	all->mlx = mlx_init();
	fd = open(map, O_RDONLY);
	if (fd == -1)
		return(ft_putstr("map error"));
	bite = 0;
	while (get_next_line(fd, &str))
	{
		bite++;
		split = ft_strsplit(str, ' ');
		i = 0;
		while(split[++i])
			;
		new = try_malloc(sizeof(t_tmp), _FL_);
		if (!tab)
		{
			tab = new;
			tmp = new;
		}
		else
		{
			tmp->next = new;
			tmp = tmp->next;
		}
		tmp->tab = try_malloc(sizeof(int *) * (i + 1), _FL_);
		i = -1;
		while (split[++i])
		{
			tmp->tab[i] = ft_atoi(split[i]);
			free(split[i]);
		}
		free(split);
	}
	quadr = try_malloc(sizeof(int *) * (bite + 1), _FL_);
	i = -1;
	tmp = tab;
	while (tmp)
	{
		quadr[++i] = tmp->tab;
		new = tmp;
		tmp = tmp->next;
		free(new);
	}
	i = -1;
	while (quadr[++i])
	{
		bite = -1;
		while ((quadr[i][++bite]))
			printf("%2d ", quadr[i][bite]);
		printf("\n");
	}
}

int		main(int ac, char **av)
{
	if (ac > 2)
	{
		ft_putstr("Too much arguments : fdf need only one argument");
		return (0);
	}
	else
		fdf(av[1]);
	return (0);
}