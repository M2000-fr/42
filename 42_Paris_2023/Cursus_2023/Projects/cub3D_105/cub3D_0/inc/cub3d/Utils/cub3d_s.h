/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:03:57 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 09:03:57 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_S_H
# define CUB3D_S_H

/* Structures */

/*
** Structure t_img_cub
** ---------------------
** Utilité : Contient les informations d'une image (texture) utilisée dans Cub3D.
**
** - img_ptr : Pointeur vers l'image créée par la bibliothèque graphique.
** - data    : Pointeur vers les données brutes de l'image (pixels).
** - width   : Largeur de l'image en pixels.
** - height  : Hauteur de l'image en pixels.
** - bpp     : Nombre de bits par pixel.
** - size_line : Taille d'une ligne de l'image en octets.
** - endian  : Indique l'ordre des octets (endianness) des données.
*/
typedef struct s_img_cub
{
	void	*img_ptr;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}			t_img_cub;

/*
** Structure t_cub
** ----------------
** Utilité : Contient l'état global du programme Cub3D, incluant la gestion de la
**           fenêtre, les textures, la map, et la position/orientation du joueur.
**
** - mlx, win        : Pointeurs vers l'instance MLX et la fenêtre créée.
** - tex_no, tex_so,
**   tex_we, tex_ea : Chemins vers les fichiers de textures pour chaque mur.
** - color_floor   : Tableau RGB pour la couleur du sol.
** - color_ceiling : Tableau RGB pour la couleur du plafond.
** - map           : Tableau 2D représentant la carte.
** - map_rows      : Nombre de lignes de la carte.
** - posx, posy    : Position du joueur sur la carte (coordonnées flottantes).
** - dirx, diry    : Vecteur directionnel du joueur.
** - planex, planey: Vecteur du plan caméra pour le champ de vision.
** - pov_left, pov_right :
**                   Flags indiquant la rotation du point de vue vers la 
**                   gauche ou la droite.
** - move_left, move_right,
**   move_forward, move_backward :
**                   Flags indiquant le mouvement dans les différentes 
**                   directions.
** - sprint        : Flag indiquant si le joueur est en mode sprint.
** - exit          : Flag indiquant la demande de sortie du programme.
** - img_tex_no, img_tex_so,
**   img_tex_we, img_tex_ea :
**                   Structures de texture associées aux différents murs.
*/
typedef struct s_cub
{
	void		*mlx;
	void		*win;
	char		*tex_no;
	char		*tex_so;
	char		*tex_we;
	char		*tex_ea;
	int			color_floor[3];
	int			color_ceiling[3];
	char		**map;
	int			map_rows;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	int			pov_left;
	int			pov_right;
	int			move_left;
	int			move_right;
	int			move_forward;
	int			move_backward;
	int			sprint;
	int			exit;
	t_img_cub	img_tex_no;
	t_img_cub	img_tex_so;
	t_img_cub	img_tex_we;
	t_img_cub	img_tex_ea;
}				t_cub;

/*
** Structure t_render
** ---------------------
** Utilité : Contient les informations nécessaires au rendu d'une colonne
**           de l'écran lors du raycasting.
**
** - cub       : Pointeur vers la structure principale t_cub.
** - x         : Position en x de la colonne en cours de rendu.
** - data      : Pointeur vers les données de l'image où s'effectue le rendu.
** - bpp       : Bits par pixel de l'image.
** - size_line : Taille en octets d'une ligne dans l'image.
*/
typedef struct s_render
{
	t_cub	*cub;
	int		x;
	char	*data;
	int		bpp;
	int		size_line;
}			t_render;

/*
** Structure t_ray_result
** -------------------------
** Utilité : Stocke les résultats du raycasting pour un rayon
**           particulier, incluant les informations sur l'intersection
**           avec un mur et les paramètres de texture.
**
** - side          : Indique si l'impact a eu lieu sur un mur vertical 
**                   (0) ou horizontal (1).
** - perpwalldist  : Distance perpendiculaire entre le joueur et le mur.
** - lineheight    : Hauteur de la ligne à dessiner pour le mur.
** - drawstart, drawend :
**                   Coordonnées de début et de fin pour le dessin de la colonne.
** - wallx         : Position exacte sur le mur où le rayon a frappé.
** - texx          : Coordonnée en x dans la texture.
** - current_tex   : Pointeur vers la texture utilisée pour le mur impacté.
** - camx          : Position de la caméra sur l'axe x (de -1 à 1).
** - raydirx, raydiry :
**                   Composantes du vecteur direction du rayon.
** - mapx, mapy    : Coordonnées de la case de la map touchée par le rayon.
** - deltadistx, deltadisty :
**                   Distances entre les intersections successives sur les
**                   axes x et y.
** - sidedistx, sidedisty :
**                   Distance initiale du joueur à la première intersection
**                   sur les axes x et y.
** - stepx, stepy  : Valeurs de pas (direction) sur les axes x et y.
** - hit           : Flag indiquant si un mur a été touché (1 si oui, 0 sinon).
*/
typedef struct s_ray_result
{
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		wallx;
	int			texx;
	t_img_cub	*current_tex;
	double		camx;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		deltadistx;
	double		deltadisty;
	double		sidedistx;
	double		sidedisty;
	int			stepx;
	int			stepy;
	int			hit;
}				t_ray_result;

/*
** Structure t_exec
** -------------------
** Utilité : Utilisée lors de l'exécution pour gérer la création et le traitement
**           de l'image affichée à l'écran.
**
** - img  : Pointeur vers l'image créée par MLX.
** - data : Pointeur vers les données de l'image.
** - bpp  : Bits par pixel de l'image.
** - sl   : Taille en octets d'une ligne de l'image.
*/
typedef struct s_exec
{
	void	*img;
	char	*data;
	int		bpp;
	int		sl;
}			t_exec;

/*
** Structure t_key
** ------------------
** Utilité : Stocke les paramètres de déplacement et de rotation
**           influencés par les entrées clavier.
**
** - ms       : Vitesse de déplacement (movement speed).
** - rs       : Vitesse de rotation (rotation speed).
** - strafex, strafey :
**              Composantes pour le déplacement en strafe (déplacement latéral).
** - olddirx  : Ancienne valeur de la direction en x
**              (pour les calculs de rotation).
** - oldplanex: Ancienne valeur du plan caméra en x
**              (pour les calculs de rotation).
*/
typedef struct s_key
{
	double	ms;
	double	rs;
	double	strafex;
	double	strafey;
	double	olddirx;
	double	oldplanex;
}			t_key;

#endif
