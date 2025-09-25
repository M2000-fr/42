/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_exec.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:01:33 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 09:01:33 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_EXEC_H
# define CUB3D_EXEC_H

/* Functions */

/*
** Function returning a int
*/

int		init_mlx(t_cub *cub);
int		get_texture_pixel(t_img_cub *tex, int x, int y);
int		key_press_cub(int keycode, t_cub *cub);
int		key_release_cub(int keycode, t_cub *cub);
int		update_loop(t_cub *cub);
int		load_textures(t_cub *cub);
int		exit_hook(t_cub *cub);

/*
** Function returning a char
*/

/*
** Function returning a void
*/

void	put_pixel(t_render *r, int y, int color);
void	set_initial_position_and_direction(t_cub *cub);
void	render_column(t_render *r, t_ray_result *res);
void	render_column_ray(t_render *r, t_ray_result *res);
void	draw_column_pixels(t_render *r, t_ray_result *res);
void	compute_ray_params(t_render *r, t_ray_result *res);
void	run_dda(t_render *r, t_ray_result *res);
void	compute_distances(t_render *r, t_ray_result *res);
void	select_texture(t_render *r, t_ray_result *res);
void	compute_texture(t_render *r, t_ray_result *res);
void	draw_scene(t_cub *cub);

#endif
