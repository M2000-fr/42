/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strealloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Theo <Theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 21:29:33 by Theo              #+#    #+#             */
/*   Updated: 2017/09/22 10:59:28 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		ft_strealloc_free(char *str, int new_size)
{
	char	*new_str;
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(str);
	new_str = try_malloc(sizeof(char) * (new_size + 1), _FL_);
	while (++i < new_size && i < len)
		new_str[i] = str[i];
	new_str[new_size] = 0;
	ft_strdel(&str);
	str = ft_strdup(new_str);
	ft_strdel(&new_str);
}

char		*ft_strealloc(char *str, int new_size)
{
	char	*new_str;
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(str);
	new_str = try_malloc(sizeof(char) * (new_size + 1), _FL_);
	while (++i < new_size && i < len)
		new_str[i] = str[i];
	new_str[new_size] = 0;
	return (new_str);
}
