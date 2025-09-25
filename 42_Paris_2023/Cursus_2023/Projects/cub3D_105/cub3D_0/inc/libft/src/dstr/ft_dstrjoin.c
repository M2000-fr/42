/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 15:12:54 by mechard           #+#    #+#             */
/*   Updated: 2024/11/06 13:57:01 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dstrjoin_wsp(char **dstr)
{
	int		i;
	char	*str;

	i = -1;
	str = NULL;
	while (dstr[++i])
	{
		str = ft_strjoin(str, dstr[i]);
		if (i < ft_dstrlen(dstr) - 1)
			str = ft_strjoin(str, " ");
	}
	return (str);
}
