/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bsq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:39:47 by mechard           #+#    #+#             */
/*   Updated: 2023/08/23 23:28:39 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	**ft_reso_bsq(t_args *arg, char **map)
{
	int x;
	int y;

	x = 0;
	y = 0;
    
    if (map)
    {
        (void)arg;
        ft_putstr_fd(1, "il y a une solution... on as juste pas pu le resoudre...\n");
    }
    else
    {
        while (x <= arg->len)
	    {
            y = 0;
            while (y <= arg->nb_line)
            {
                y++;
            }
            x++;
        }
    }
    return (NULL);
}