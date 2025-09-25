/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 09:26:41 by tarchen           #+#    #+#             */
/*   Updated: 2017/08/13 10:20:18 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char				*ft_strinsert(char *dest, char *str, size_t n)
{
	char			*tmp;
	size_t			i;
	size_t			j;

	if (!dest || !str)
		return (NULL);
	tmp = try_malloc(sizeof(char) * (ft_strlen(dest) + ft_strlen(str) + 1), _FL_);
	i = -1;
	while (dest[++i] && i < n)
		tmp[i] = dest[i];
	j = -1;
	i--;
	while (str[++j])
		tmp[++i] = str[j];
	n--;
	while (dest[++n])
		tmp[++i] = dest[n];
	return (tmp);
}
