/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdr_proc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 11:59:10 by mechard           #+#    #+#             */
/*   Updated: 2025/06/11 11:59:10 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_texture_file(const char *path)
{
	size_t	len;
	char	*dup;

	if (!path)
		return (1);
	dup = ft_strdup(path);
	if (!dup)
		return (1);
	len = ft_strlen(dup);
	while (len > 0 && (dup[len - 1] == '\n' || dup[len - 1] == '\r'))
	{
		dup[len - 1] = '\0';
		len = ft_strlen(dup);
	}
	if (len < 4 || ft_strcmp(dup + len - 4, ".xpm") != 0)
	{
		ft_putendl_fd(TEXT_EXT_ERROR, 2);
		return (free(dup), 1);
	}
	else if (access(dup, F_OK) != 0)
	{
		ft_putendl_fd(TEXT_NOT_FOUND, 2);
		return (free(dup), 1);
	}
	return (free(dup), 0);
}

static int	parse_color_line(char *line, int color[3])
{
	char	**n;

	n = ft_split(line + 2, ',');
	if (!n)
		return (ft_putendl_fd(COLOR_ALLOC_ER, 2), 1);
	if (ft_dstrlen(n) != 3 || count_cara(line, ',') != 2)
		return (free(n[0]), free(n[1]), free(n[2]), free(n),
			ft_putendl_fd(COLOR_FORMAT_ER, 2), 1);
	if (ft_strisdigit(n[0]) && ft_strisdigit(n[1]) && ft_strisdigit(n[2])
		&& ft_overflow(n[0]) && ft_overflow(n[1]) && ft_overflow(n[2]))
	{
		color[0] = ft_atoi(n[0]);
		color[1] = ft_atoi(n[1]);
		color[2] = ft_atoi(n[2]);
		(free(n[0]), free(n[1]), free(n[2]), free(n));
	}
	else
		return (free(n[0]), free(n[1]), free(n[2]), free(n),
			ft_putendl_fd(COLOR_FORMAT_ER, 2), 1);
	if ((color[0] > 255 || color[0] < 0) || (color[1] > 255 || color[1] < 0)
		|| (color[2] > 255 || color[2] < 0))
		return (color[0] = -1, ft_putendl_fd(COLOR_ALLOC_ER, 2), 1);
	return (0);
}

int	convert_map_list(t_list *map_list, t_cub *cub)
{
	int	count;

	count = ft_lstsize(map_list);
	cub->map = malloc(sizeof(char *) * (count + 1));
	if (!cub->map)
		return (1);
	count = 0;
	while (map_list)
	{
		cub->map[count++] = ft_strdup((char *)map_list->content);
		map_list = map_list->next;
	}
	cub->map[count] = NULL;
	cub->map_rows = count;
	if (!validate_map(cub->map))
		return (1);
	return (0);
}

int	parse_header_line(char *line, t_cub *cub)
{
	int	header;

	header = elements_order(line);
	if (header == 0 && !cub->tex_no)
		cub->tex_no = ft_strdup(line + 3);
	else if (header == 1 && !cub->tex_so)
		cub->tex_so = ft_strdup(line + 3);
	else if (header == 2 && !cub->tex_we)
		cub->tex_we = ft_strdup(line + 3);
	else if (header == 3 && !cub->tex_ea)
		cub->tex_ea = ft_strdup(line + 3);
	else if (header == 4 && cub->color_floor[0] == -1)
		return (parse_color_line(line, cub->color_floor));
	else if (header == 5 && cub->color_ceiling[0] == -1)
		return (parse_color_line(line, cub->color_ceiling));
	else
		return (ft_putendl_fd(HEADER_INCOMPL, 2), 1);
	if ((header == 0 && check_texture_file(cub->tex_no)) || (header == 1
			&& check_texture_file(cub->tex_so)) || (header == 2
			&& check_texture_file(cub->tex_we)) || (header == 3
			&& check_texture_file(cub->tex_ea)) || (header == 4
			&& cub->color_floor[0] == -1) || (header == 5
			&& cub->color_ceiling[0] == -1))
		return (1);
	return (0);
}
