/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 08:04:20 by mechard           #+#    #+#             */
/*   Updated: 2025/03/29 08:04:20 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include "libft.h"

/* Headers */

/*
** Header pour tout les defines
*/
# include "cub3d_d.h"

/*
** Header pour toutes les structures
*/
# include "cub3d_s.h"

/*
** Header de la partie parsing
*/
# include "cub3d_parsing.h"

/*
** Header de la partie exécution
*/
# include "cub3d_exec.h"

/*
** Fonctions de libération et autres fonctions générales
*/

int		free_textures(t_cub *cub);
int		free_all_cub(t_cub *cub);
int		free_lac(char *line, t_cub *cub);
void	free_cub(t_cub *cub);

#endif
