/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stradd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 14:02:54 by mechard           #+#    #+#             */
/*   Updated: 2025/03/25 17:08:30 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dstradd(char	***dstr, char	*str)
{
	char	**new_dstr;
	int		i;

	i = 0;
	if (!dstr)
		return ;
	if (!*dstr)
	{
		*dstr = malloc(sizeof(char *));
		if (!*dstr)
			return;
		(*dstr)[0] = NULL;
	}
	i = ft_dstrlen(*dstr);
	new_dstr = malloc(sizeof(char *) * (i + 2));
	if (!new_dstr)
		return ;
	i = 0;
	while ((*dstr)[i])
	{
		new_dstr[i] = (*dstr)[i];
		++i;
	}
	new_dstr[i] = ft_strdup(str);
	new_dstr[i + 1] = NULL;
	free(*dstr);
	*dstr = new_dstr;
}
