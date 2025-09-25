/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/04/04 09:06:43 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 09:06:43 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_D_H
# define CUB3D_D_H

/*
** WIN_WIDTH et WIN_HEIGHT
** --------------------------
**
** Utilisés dans :
**   - draw_scene() (run_draw.c)     : Création de l'image et boucle de rendu.
**   - compute_distances() (calc_rays.c)   : Calcul de la hauteur de la ligne.
**   - draw_upper_and_wall_pixels() (render.c) et
**     draw_floor_pixels() (render.c)      : Dessin du plafond et du sol.
*/

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

/*
** Codes clavier
** ---------------
**
** (KEY_MAJ_L, KEY_MAJ_R, KEY_BACKWARD, KEY_RIGHT, KEY_FORWARD, KEY_LEFT,
**  KEY_ESC, KEY_Z, KEY_W, KEY_S, KEY_Q, KEY_D, KEY_A)
**
** Utilisés dans :
**   - key_press_cub() (keys.c)    : Gestion des appuis sur les touches.
**   - key_release_cub() (keys.c)  : Gestion des relâchements des touches.
*/

# define KEY_MAJ_L 65505
# define KEY_MAJ_R 65506
# define KEY_BACKWARD 65364
# define KEY_RIGHT 65363
# define KEY_FORWARD 65362
# define KEY_LEFT 65361
# define KEY_ESC 65307
# define KEY_Z 122
# define KEY_W 119
# define KEY_S 115
# define KEY_Q 113
# define KEY_D 100
# define KEY_A 97

/*
** Messages d'erreur pour les textures
** -------------------------------------
**
** (TEXT_EXT_ERROR, TEXT_NOT_FOUND)
**
** Utilisés dans :
**   - check_texture_file() (hdr_proc.c)
**     Vérification de l'extension et de l'existence
**     des fichiers de texture, appelés par parse_header_line().
*/

# define TEXT_EXT_ERROR "Error\nInvalid texture extension"
# define TEXT_NOT_FOUND "Error\nTexture file not found"

/*
** Erreurs liées au fichier
** -------------------------
**
******************* HEADER_INCOMPL *******************
**
** Utilisé dans :
**   - read_header() (parsing_file.c)    : En-tête incomplet ou incorrect.
**   - parse_header_line() (hdr_proc.c)  : Erreur lors du parsing
**                                         d'une ligne d'en-tête.
**
******************* FILE_FORMAT_IN *******************
**
** Utilisé dans :
**   - read_header() (parsing_file.c) : Format de fichier incorrect.
**
******************* FILE_EXTENS_IN *******************
**
** Utilisé dans :
**   - parse_file() (parsing_file.c)  : Vérification de l'extension du fichier.
**
******************* FILE_CANT_OPEN *******************
**
** Utilisé dans :
**   - parse_file() (parsing_file.c)  : Incapacité à ouvrir le fichier.
*/

# define HEADER_INCOMPL "Error\nIncomplete or incorrect header"
# define FILE_FORMAT_IN "Error\nIncorrect file format"
# define FILE_EXTENS_IN "Error\nInvalid file extension"
# define FILE_CANT_OPEN "Error\nCannot open file"

/*
** Erreurs liées à la carte
** -------------------------------------------
**
******************** MAP_INVALID *********************
**
** Utilisé dans :
**   - validate_map() (map_checker.c) : Indique que la carte est invalide.
**
******************* MAP_NOT_FOUND ********************
**
** Utilisé dans :
**   - parse_file() (parsing_file.c)  : Aucune carte trouvée dans le fichier.
**
******************* INVALID_STA_PO *******************
**
** Utilisé dans :
**   - validate_map() (map_checker.c) : Position de départ invalide.
**
******************* MAP_NOT_SURROU *******************
**
** Utilisé dans :
**   - validate_map() (map_checker.c)
**     La carte n'est pas correctement entourée de murs.
**
******************* COLOR_ALLOC_ER *******************
**
** Utilisé dans :
**   - parse_color_line() (hdr_proc.c°
**     Erreur d'allocation ou de valeurs incorrectes pour les couleurs.
*/

# define MAP_INVALID "Error\nMap invalid"
# define MAP_NOT_FOUND "Error\nNo map found"
# define INVALID_STA_PO "Error\nInvalid starting position"
# define MAP_NOT_SURROU "Error\nMap is not surrounded by walls"
# define COLOR_ALLOC_ER "Error\nColor allocation error"
# define COLOR_FORMAT_ER "Error\nColor format error"

/* Erreurs liées au mlx
** -------------------------
**
***************** MLX_MALLOC_ERROR *******************
**
** Utilisé dans :
**  
	- init_mlx (init_mlx.c) : Indique que la mlx n'as pas pu effectuer l'allocation.
**
***************** DIS_CREAT_ERROR *******************
**
** Utilisé dans :
**   - init_mlx (init_mlx.c) : Indique que la fenêtre n'as pas pu être créé.*/

# define MLX_MALLOC_ERROR "Error\nMlx initialization failed\nErreur \
d'inisialisation"
# define DIS_CREAT_ERROR "Error\nWindows creation failed\nErreur d'inisialisation"

#endif
