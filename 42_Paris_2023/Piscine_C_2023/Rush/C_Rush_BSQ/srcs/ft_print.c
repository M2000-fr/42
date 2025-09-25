/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 13:26:36 by mechard           #+#    #+#             */
/*   Updated: 2023/08/23 21:07:43 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	ft_putstr_fd(int std, char *str)
{
	write(std, str, ft_strlen(str));
}

void	ft_puterror(t_args *arg, char **map, char *str)
{
	int	i;

	i = 0;
	(void)str;
	while (map[i])
		i++;
	if (i != arg->nb_line)
		ft_putstr_fd(1, "map error\n");
}
