/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind_ls_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 03:46:40 by tarchen           #+#    #+#             */
/*   Updated: 2017/07/26 01:45:25 by Theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

/*
** check si les charactere de to_find sont dans str
** (dans ninporte quelle position ou ordre)
*/

int			ft_strfind_ls_char(char *str, char *to_find)
{
	int		i;
	int		j;
	size_t	found;

	i = 0;
	j = 0;
	found = 0;
	if (!str || !to_find)
		return (0);
	while (str[i])
	{
		while (to_find[j])
		{
			if (str[i] == to_find[j])
				found++;
			j++;
		}
		j = 0;
		i++;
	}
	return (found == ft_strlen(str) ? 1 : 0);
}
