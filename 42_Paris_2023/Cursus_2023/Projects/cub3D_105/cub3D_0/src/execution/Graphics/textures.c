/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:43:14 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 08:43:14 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*          (Gestion des textures et résolution de chemins d'accès)           */
/* ************************************************************************** */

#include "cub3d.h"
#include <limits.h>
#include <unistd.h>

int	get_texture_pixel(t_img_cub *tex, int x, int y)
{
	int	idx;

	if (x < 0)
		x = 0;
	if (x >= tex->width)
		x = tex->width - 1;
	if (y < 0)
		y = 0;
	if (y >= tex->height)
		y = tex->height - 1;
	idx = (y * tex->size_line) + (x * (tex->bpp / 8));
	return (*(int *)(tex->data + idx));
}

char	*get_executable_dir(void)
{
	char	exe_path[PATH_MAX];
	ssize_t	len;
	char	*last_slash;
	size_t	dir_len;
	char	*dir;

	len = readlink("/proc/self/exe", exe_path, sizeof(exe_path) - 1);
	if (len == -1)
	{
		perror("readlink");
		return (NULL);
	}
	exe_path[len] = '\0';
	last_slash = ft_strrchr(exe_path, '/');
	if (!last_slash)
		return (NULL);
	dir_len = last_slash - exe_path + 1;
	dir = malloc(dir_len + 1);
	if (!dir)
		return (NULL);
	ft_strncpy(dir, exe_path, dir_len);
	dir[dir_len] = '\0';
	return (dir);
}

char	*resolve_path(char *relative_path)
{
	char	*clean_path;
	char	*base_dir;
	size_t	full_len;
	char	*full_path;

	clean_path = relative_path;
	if (strncmp(relative_path, "./", 2) == 0)
		clean_path = relative_path + 2;
	base_dir = get_executable_dir();
	if (!base_dir)
		return (NULL);
	full_len = ft_strlen(base_dir) + ft_strlen(clean_path) + 1;
	full_path = malloc(full_len);
	if (!full_path)
	{
		free(base_dir);
		return (NULL);
	}
	ft_strcpy(full_path, base_dir);
	ft_strcat(full_path, clean_path);
	free(base_dir);
	if (full_path[ft_strlen(full_path) - 1] == '\n')
		full_path[ft_strlen(full_path) - 2] = '\0';
	return (full_path);
}

static int	load_texture(t_img_cub *tex, void *mlx, char *path)
{
	char	*rl_path;

	rl_path = resolve_path(path);
	tex->img_ptr = mlx_xpm_file_to_image(mlx, rl_path,
			&tex->width, &tex->height);
	free(rl_path);
	if (!tex->img_ptr)
	{
		ft_putendl_fd("Error: impossible de charger la texture", 2);
		return (1);
	}
	tex->data = mlx_get_data_addr(tex->img_ptr, &tex->bpp,
			&tex->size_line, &tex->endian);
	return (0);
}

int	load_textures(t_cub *cub)
{
	if (load_texture(&cub->img_tex_no, cub->mlx, cub->tex_no))
		return (1);
	if (load_texture(&cub->img_tex_so, cub->mlx, cub->tex_so))
		return (1);
	if (load_texture(&cub->img_tex_we, cub->mlx, cub->tex_we))
		return (1);
	if (load_texture(&cub->img_tex_ea, cub->mlx, cub->tex_ea))
		return (1);
	return (0);
}
