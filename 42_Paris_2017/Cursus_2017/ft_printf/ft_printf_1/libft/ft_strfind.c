/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 14:34:11 by tarchen           #+#    #+#             */
/*   Updated: 2017/08/31 02:51:22 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

/*
** check si un des caracteres de s est compris dans c.
*/

int			ft_strsfind(char *s, char *c)
{
	int		i;
	int		j;

	i = -1;
	while (s[++i])
	{
		j = -1;
		while (c[++j])
			if (s[i] == c[j])
				return (i);
	}
	return (-1);
}

int			ft_strfind_we(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		i++;
	return (i);
}


int			ft_strfind(char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] != (char)c)
		return (-1);
	return (i);
}
