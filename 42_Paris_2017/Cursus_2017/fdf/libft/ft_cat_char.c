/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 13:30:39 by tarchen           #+#    #+#             */
/*   Updated: 2018/01/24 16:31:24 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_cat_char(char c, int nb_char)
{
	char	*dest;
	int		i;

	i = -1;
	if (nb_char < 1)
		return (ft_strdup(""));
	dest = try_malloc(sizeof(char) * (nb_char + 1), _FL_);
	while (++i < nb_char)
		dest[i] = c;
	return (dest);
}
