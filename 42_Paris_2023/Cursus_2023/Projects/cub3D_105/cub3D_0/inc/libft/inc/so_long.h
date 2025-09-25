/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:38:25 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 02:42:17 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>

# ifndef INVALID_NAME
#  define INVALID_NAME "\033[1;31mError\033[0m\nLa nom de la map n'est pas \
valide\n"
# endif

# ifndef INVALID_MAP
#  define INVALID_MAP "\033[1;31mError\033[0m\nLa map n'est pas valide\n"
# endif

# ifndef INVALID_ROAD
#  define INVALID_ROAD "\033[1;31mError\033[0m\nIl n'y a pas de chemin valide\n"
# endif

# ifndef INVALID_NB
#  define INVALID_NB "\033[1;31mError\033[0m\nLe nombre de spawn ou de sortie \
n'est pas valide ! (Maximum 1 de chaque)\n"
# endif

# ifndef INVALID_CARA
#  define INVALID_CARA "\033[1;31mError\033[0m\nSeul les caracteres 01CEP sont \
accepte !\n"
# endif

# ifndef INVALID_COL
#  define INVALID_COL "\033[1;31mError\033[0m\nLe nombre de collectibles n'est \
pas valide ! (Au moins 1)\n"
# endif

# ifndef ERROR_REC
#  define ERROR_REC "\033[1;31mError\033[0m\nUne erreur est survenue lors de la \
recuperation de la map !\n\033[1m\033[1;33mSeul des fichiers peuvent etre traites !\
\033[0m\n"
# endif

# ifndef ERROR_COL
#  define ERROR_COL "\033[1;31mError\033[0m\nUne erreur est survenue lors de la \
recuperation des collectibles\n"
# endif

# ifndef VALID_CARA
#  define VALID_CARA "01CEP"
# endif

# ifndef NOT_SUCCESS
#  define NOT_SUCCESS "\rIl te manque %d collectible pour pouvoir terminer \
les niveaux !\n"
# endif

# ifndef NOTS_SUCCESS
#  define NOTS_SUCCESS "\rIl te manque %d collectibles pour pouvoir terminer \
les niveaux !\n"
# endif

# ifndef SUCCESS
#  define SUCCESS "\r\033[1;32mBravo \033[0m! Vous avez gagne la partie !\nLe \
nombre de pas pendant cette partie est de %d\n"
# endif

# ifndef COL
#  define COL "/tools_so_long/sprites/col.xpm"
# endif

# ifndef EXI
#  define EXI "/tools_so_long/sprites/exi.xpm"
# endif

# ifndef FIN
#  define FIN "/tools_so_long/sprites/fin.xpm"
# endif

# ifndef PLA
#  define PLA "/tools_so_long/sprites/pla.xpm"
# endif

# ifndef ROC
#  define ROC "/tools_so_long/sprites/roc.xpm"
# endif

# ifndef SOL
#  define SOL "/tools_so_long/sprites/sol.xpm"
# endif

typedef struct s_game
{
	int		i;
	char	**map;
	int		width;
	int		len;
	int		nb_collectibles;

	void	*col;
	void	*exi;
	void	*roc;
	void	*sol;
	void	*pla;
	t_img	*canva;

	int		step;
	int		exit;
	int		player_x;
	int		player_y;
	int		collectibles;

	void	*mlx_ptr;
	void	*win_ptr;
	int		keycode_prev;
}			t_game;

typedef struct s_map
{
	int		player_x;
	int		player_y;

	int		x;
	int		y;
	int		i;
	int		width;
	int		len;
	char	**map;

	int		nb_p;
	int		nb_c;
	int		nb_e;
}			t_map;

int			verif_name(char *str);
int			count_line(char *str);
int			check_cara(char **map, char *cara, t_map *coor);
int			verif_cara(char **map, t_map *coor);
int			key_press(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);
int			ft_init_sprites(t_game *game);
int			map_comp(t_game *game, char **map);
int			ft_set_img(t_game *game);
int			close_window(t_game *game);

char		**recup_map(char *str);
char		**verif_map(char *str, char **map, t_game *game);

void		ft_dfree(char **str);
void		free_game(t_game *game);
void		ft_init_null(t_game *game);
void		map_init(t_map *map, char **str);
void		*open_windows(t_game *game);
void		ft_coor(int x, int y, t_map *coor);
void		draw_sprite(t_game *game, t_img *img, int x, int y);
void		ft_moove(int keycode, t_game *game);
void		ft_collect(t_game *game);
void		ft_finish(t_game *game);

#endif