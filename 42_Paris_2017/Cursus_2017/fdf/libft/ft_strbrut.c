/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strbrut.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/23 08:16:27 by tarchen           #+#    #+#             */
/*   Updated: 2017/10/14 20:34:00 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char		*ft_strbrut(char *str)
{
	char	*new;
	int		j;
	int		i;

	i = -1;
	j = 0;
	while (str[++i])
		if (str[i] == '\n' || str[i] == '\t')
			j++;
	new = try_malloc(sizeof(char) * (i + j + 1), _FL_);
	i = -1;
	j = -1;
	while (str[++i])
	{
		if (str[i] == '\n' || str[i] == '\t')
		{
			new[++j] = '\\';
			new[++j] = str[i] == '\n' ? 'n' : 't';
		}
		else
			new[++j] = str[i];
	}
	return (new);
}

char		*ft_strbrut_single(char *str, int size)
{
	int		i;

	i = -1;
	while (++i < size - 1)
	{
		if (str[i] == '\n')
			str[i] = 'n';
		else if (str[i] == '\0')
			str[i] = '0';
		else if (str[i] == '\t')
			str[i] = 't';
	}
	return (str);
}

char		*ft_strbrut_blind(char *str, int size)
{
	char	*new;
	int		j;
	int		i;

	i = -1;
	j = 0;
	while (++i < size)
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\0')
			j++;
	new = try_malloc(sizeof(char) * (i + j + 1), _FL_);
	i = -1;
	j = -1;
	while (++i < size - 1)
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\0')
		{
			new[++j] = '\\';
			new[++j] = str[i] == '\n' ? 'n' : str[i] == '\t' ? 't' : '0';
		}
		else
			new[++j] = str[i];
	}
	return (new);
}

