/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:39:27 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 08:39:27 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                  (Gestion des entrées clavier pour Cub3D)                  */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press_cub(int keycode, t_cub *cub)
{
	if (keycode == KEY_W || keycode == KEY_Z || keycode == KEY_FORWARD)
		cub->move_forward = 1;
	else if (keycode == KEY_S || keycode == KEY_BACKWARD)
		cub->move_backward = 1;
	else if (keycode == KEY_A || keycode == KEY_Q)
		cub->move_left = 1;
	else if (keycode == KEY_D)
		cub->move_right = 1;
	else if (keycode == KEY_RIGHT)
		cub->pov_right = 1;
	else if (keycode == KEY_LEFT)
		cub->pov_left = 1;
	else if (keycode == KEY_MAJ_L || keycode == KEY_MAJ_R)
		cub->sprint = 1;
	else if (keycode == KEY_ESC)
		cub->exit = 1;
	return (0);
}

int	key_release_cub(int keycode, t_cub *cub)
{
	if (keycode == KEY_W || keycode == KEY_Z || keycode == KEY_FORWARD)
		cub->move_forward = 0;
	else if (keycode == KEY_S || keycode == KEY_BACKWARD)
		cub->move_backward = 0;
	else if (keycode == KEY_A || keycode == KEY_Q)
		cub->move_left = 0;
	else if (keycode == KEY_D)
		cub->move_right = 0;
	else if (keycode == KEY_RIGHT)
		cub->pov_right = 0;
	else if (keycode == KEY_LEFT)
		cub->pov_left = 0;
	else if (keycode == KEY_MAJ_L || keycode == KEY_MAJ_R)
		cub->sprint = 0;
	else if (keycode == KEY_ESC)
		cub->exit = 0;
	return (0);
}
