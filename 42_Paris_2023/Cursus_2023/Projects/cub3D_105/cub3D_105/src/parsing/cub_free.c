/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/04/04 08:29:15 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 08:29:15 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                              cub_free.c                                    */
/* ************************************************************************** */

#include "cub3d.h"

int	free_textures(t_cub *cub)
{
	if (cub->tex_no)
		free(cub->tex_no);
	if (cub->tex_so)
		free(cub->tex_so);
	if (cub->tex_we)
		free(cub->tex_we);
	if (cub->tex_ea)
		free(cub->tex_ea);
	if (cub->mlx)
	{
		if (cub->img_tex_no.img_ptr)
			mlx_destroy_image(cub->mlx, cub->img_tex_no.img_ptr);
		if (cub->img_tex_so.img_ptr)
			mlx_destroy_image(cub->mlx, cub->img_tex_so.img_ptr);
		if (cub->img_tex_we.img_ptr)
			mlx_destroy_image(cub->mlx, cub->img_tex_we.img_ptr);
		if (cub->img_tex_ea.img_ptr)
			mlx_destroy_image(cub->mlx, cub->img_tex_ea.img_ptr);
	}
	return (0);
}

int	free_lac(char *line, t_cub *cub)
{
	free(line);
	free_textures(cub);
	return (1);
}

int	free_all_cub(t_cub *cub)
{
	ft_dfree(cub->map);
	free_textures(cub);
	return (0);
}
