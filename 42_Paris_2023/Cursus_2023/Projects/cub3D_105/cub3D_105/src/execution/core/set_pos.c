/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:41:51 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 08:41:51 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*           (Initialisation de la position et direction du joueur)           */
/* ************************************************************************** */

#include "cub3d.h"

int	is_starting_position(char c)
{
	int	result;

	result = 0;
	if (c == 'N')
		result = 1;
	else if (c == 'S')
		result = 1;
	else if (c == 'E')
		result = 2;
	else if (c == 'W')
		result = 2;
	return (result);
}

void	configure_direction_ns(t_cub *cub, char c)
{
	if (c == 'N')
	{
		cub->dirx = 0.0;
		cub->diry = -1.0;
		cub->planex = 0.66;
		cub->planey = 0.0;
	}
	else if (c == 'S')
	{
		cub->dirx = 0.0;
		cub->diry = 1.0;
		cub->planex = -0.66;
		cub->planey = 0.0;
	}
}

void	configure_direction_we(t_cub *cub, char c)
{
	if (c == 'W')
	{
		cub->dirx = -1.0;
		cub->diry = 0.0;
		cub->planex = 0.0;
		cub->planey = -0.66;
	}
	else if (c == 'E')
	{
		cub->dirx = 1.0;
		cub->diry = 0.0;
		cub->planex = 0.0;
		cub->planey = 0.66;
	}
}

void	set_initial_position_and_direction(t_cub *cub)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (cub->map[row] != 0)
	{
		col = 0;
		while (cub->map[row][col] != '\0')
		{
			c = cub->map[row][col];
			if (is_starting_position(c))
			{
				cub->posx = col + 0.5;
				cub->posy = row + 0.5;
				configure_direction_ns(cub, c);
				configure_direction_we(cub, c);
				cub->map[row][col] = '0';
				return ;
			}
			col++;
		}
		row++;
	}
}
