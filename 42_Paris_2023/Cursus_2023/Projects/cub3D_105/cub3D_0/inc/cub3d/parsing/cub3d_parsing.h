/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parsing.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:02:17 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 09:02:17 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_PARSING_H
# define CUB3D_PARSING_H

/* Functions */

/*
** Function returning a int
*/

int		parse_file(char *filename, t_cub *cub);
int		parse_header_line(char *line, t_cub *cub);
int		is_valid_extension(char *filename);
int		is_header_line(const char *line);
int		validate_map(char **map);
int		convert_map_list(t_list *map_list, t_cub *cub);
int		elements_order(char *line);

/*
** Function returning a char
*/

/*
** Function returning a void
*/

#endif
