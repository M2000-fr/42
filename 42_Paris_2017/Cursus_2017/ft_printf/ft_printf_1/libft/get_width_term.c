/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width_term.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 05:38:14 by tarchen           #+#    #+#             */
/*   Updated: 2017/08/11 06:05:01 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <sys/ioctl.h>

/*
** unsigned short	ws_row;		** rows, 	  in characters
** unsigned short	ws_col;		** columns,   in characters
** unsigned short	ws_xpixel;	** horizontal size, pixels
** unsigned short	ws_ypixel;	** vertical   size, pixels
*/

/*
** option = 1 for ws_row	-> rows, 	  in characters
** option = 2 for ws_col	-> columns,   in characters
** option = 3 for ws_xpixel	-> horizontal size, pixels
** option = 4 for ws_ypixel	-> vertical   size, pixels
*/

int					get_width_term(int option)
{
	struct winsize	w;
	int				width[4];

	ioctl(0, TIOCGWINSZ, &w);
	width[0] = (int)w.ws_row;
	width[1] = (int)w.ws_col;
	width[2] = (int)w.ws_xpixel;
	width[3] = (int)w.ws_ypixel;
	return (width[option]);
}
