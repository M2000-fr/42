/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hdr_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 08:26:48 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 08:26:48 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               hdr_check.c                                  */
/* ************************************************************************** */

#include "cub3d.h"

int	is_valid_extension(char *filename)
{
	size_t	len;

	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strcmp(filename + len - 4, ".cub") == 0);
}

int	is_header_line(const char *line)
{
	if (!line || !*line)
		return (0);
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "SO ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "WE ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "EA ", 3) == 0)
		return (1);
	if (ft_strncmp(line, "F ", 2) == 0)
		return (1);
	if (ft_strncmp(line, "C ", 2) == 0)
		return (1);
	return (0);
}

int	elements_order(char *line)
{
	char	*exp[6];
	int		i;

	exp[0] = "NO";
	exp[1] = "SO";
	exp[2] = "WE";
	exp[3] = "EA";
	exp[4] = "F";
	exp[5] = "C";
	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(line, exp[i], ft_strlen(exp[i])))
			return (i);
		i++;
	}
	return (i);
}
