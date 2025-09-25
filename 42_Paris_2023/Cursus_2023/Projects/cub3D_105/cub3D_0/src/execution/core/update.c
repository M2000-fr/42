/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:44:40 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 08:44:40 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*           (Mise à jour des translations et rotations du joueur)            */
/* ************************************************************************** */

#include "cub3d.h"
#include <math.h>

void	update_translation_forward_backward(t_cub *cub, t_key *key)
{
	if (cub->move_forward)
	{
		if (cub->map[(int)(cub->posy)]
			[(int)(cub->posx + cub->dirx * key->ms)] != '1')
			cub->posx += cub->dirx * key->ms;
		if (cub->map[(int)(cub->posy + cub->diry * key->ms)]
			[(int)cub->posx] != '1')
			cub->posy += cub->diry * key->ms;
	}
	else if (cub->move_backward)
	{
		if (cub->map[(int)(cub->posy)]
			[(int)(cub->posx - cub->dirx * key->ms)] != '1')
			cub->posx -= cub->dirx * key->ms;
		if (cub->map[(int)(cub->posy - cub->diry * key->ms)]
			[(int)cub->posx] != '1')
			cub->posy -= cub->diry * key->ms;
	}
}

void	update_translation_strafe(t_cub *cub, t_key *key)
{
	if (cub->move_left)
	{
		key->strafex = cub->diry;
		key->strafey = -cub->dirx;
		if (cub->map[(int)(cub->posy)]
			[(int)(cub->posx + key->strafex * key->ms)] != '1')
			cub->posx += key->strafex * key->ms;
		if (cub->map[(int)(cub->posy + key->strafey * key->ms)]
			[(int)cub->posx] != '1')
			cub->posy += key->strafey * key->ms;
	}
	else if (cub->move_right)
	{
		key->strafex = -cub->diry;
		key->strafey = cub->dirx;
		if (cub->map[(int)(cub->posy)]
			[(int)(cub->posx + key->strafex * key->ms)] != '1')
			cub->posx += key->strafex * key->ms;
		if (cub->map[(int)(cub->posy + key->strafey * key->ms)]
			[(int)cub->posx] != '1')
			cub->posy += key->strafey * key->ms;
	}
}

void	update_rotation(t_cub *cub, t_key *key)
{
	if (cub->pov_right)
	{
		key->olddirx = cub->dirx;
		cub->dirx = cub->dirx * cos(key->rs) - cub->diry * sin(key->rs);
		cub->diry = key->olddirx * sin(key->rs) + cub->diry * cos(key->rs);
		key->oldplanex = cub->planex;
		cub->planex = cub->planex * cos(key->rs) - cub->planey * sin(key->rs);
		cub->planey = key->oldplanex * sin(key->rs) + cub->planey \
		* cos(key->rs);
	}
	else if (cub->pov_left)
	{
		key->olddirx = cub->dirx;
		cub->dirx = cub->dirx * cos(-key->rs) - cub->diry * sin(-key->rs);
		cub->diry = key->olddirx * sin(-key->rs) + cub->diry * cos(-key->rs);
		key->oldplanex = cub->planex;
		cub->planex = cub->planex * cos(-key->rs) - cub->planey * sin(-key->rs);
		cub->planey = key->oldplanex * sin(-key->rs) + cub->planey \
		* cos(-key->rs);
	}
}

void	update_translation(t_cub *cub, t_key *key)
{
	update_translation_forward_backward(cub, key);
	update_translation_strafe(cub, key);
}

int	update_loop(t_cub *cub)
{
	t_key	key;

	key.ms = 0.01;
	key.rs = 0.01;
	if (cub->exit)
		return (exit_hook(cub));
	if (cub->sprint)
	{
		key.ms *= 5;
		key.rs *= 5;
	}
	if (cub->move_forward || cub->move_backward
		|| cub->move_left || cub->move_right)
		update_translation(cub, &key);
	if (cub->pov_right || cub->pov_left)
		update_rotation(cub, &key);
	draw_scene(cub);
	return (0);
}
