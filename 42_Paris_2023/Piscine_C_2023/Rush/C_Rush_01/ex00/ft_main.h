/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhadini <abhadini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 23:19:22 by abhadini          #+#    #+#             */
/*   Updated: 2023/08/13 23:34:45 by abhadini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAIN_H
# define FT_MAIN_H
# define TOP 0
# define BOTTOM 1
# define LEFT 2
# define RIGHT 3
# include <unistd.h>

void	ft_putchar(char const c);
void	init_tab(int (*tab)[4][4]);
void	print_tab(int const tab[4][4]);
void	set_consign(char const *consign, int (*tab)[4][4]);
void	place(int const consign[4][4], int (*tab)[4][4], int pos);
void	place1234_front_of_4(int const consign[4][4], int (*tab)[4][4]);
void	place4_front_of_1(int const consign[4][4], int (*tab)[4][4]);
int		check_colnline(int const tab[4][4], int const y, int const x,
			int const value);
int		check_top(int const consign[4][4], int const tab[4][4]);
int		check_bottom(int const consign[4][4], int const tab[4][4]);
int		check_left(int const consign[4][4], int const tab[4][4]);
int		check_right(int const consign[4][4], int const tab[4][4]);
int		check_all_views(int const consign[4][4], int const tab[4][4]);
int		check_consign(char const *consign);
int		check_top_range(int const consign[4][4], int const tab[4][4],
			int const x);
int		check_bottom_range(int const consign[4][4], int const tab[4][4],
			int const x);
int		check_left_range(int const consign[4][4], int const tab[4][4],
			int const x);
int		check_right_range(int const consign[4][4], int const tab[4][4],
			int const x);
int		is_filled_good(int const consign[4][4], int const tab[4][4]);

#endif
