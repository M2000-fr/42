/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 06:06:41 by tarchen           #+#    #+#             */
/*   Updated: 2017/06/04 17:14:34 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char			**ft_stradd(char **str, int *sizestr, char *new_elem)
{
	char		**tmp;
	int			i;

	i = 0;
	tmp = try_malloc(sizeof(char*) * (*sizestr + 1), _FL_);
	while (i < *sizestr)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = ft_strdup(new_elem);
	*sizestr += 1;
	return (tmp);
}
