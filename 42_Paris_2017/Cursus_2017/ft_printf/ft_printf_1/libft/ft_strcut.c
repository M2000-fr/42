/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 05:29:12 by tarchen           #+#    #+#             */
/*   Updated: 2017/09/19 00:26:16 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int			ft_strcut_f(char *str, int start, int end)
{
	char	*res;
	int		i;

	i = 0;
	while (i < start && str[i])
		i++;
	if (i != start)
		return (-1);
	res = try_malloc(sizeof(char) * ((end - start) + 2), _FL_);
	while (i <= end && str[i])
	{
		res[i - start] = str[i];
		i++;
	}
	res[i - start] = '\0';
	if (i != end + 1)
		return (-1);
	ft_strdel(&str);
	str = ft_strdup(res);
	ft_strdel(&res);
	return (ft_strlen(str));
}


char		*ft_strcut(char *str, int start, int end)
{
	char	*res;
	int		i;

	i = 0;
	while (i < start && str[i])
		i++;
	if (i != start)
		return (NULL);
	res = try_malloc(sizeof(char) * ((end - start) + 2), _FL_);
	while (i <= end && str[i])
	{
		res[i - start] = str[i];
		i++;
	}
	res[i - start] = '\0';
	if (i != end + 1)
		return (NULL);
	return (res);
}

