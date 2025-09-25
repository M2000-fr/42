/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchartostr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 23:15:16 by tarchen           #+#    #+#             */
/*   Updated: 2017/10/11 11:09:45 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

// char		*ft_wcharstrtostr(wchar_t *wc)
// {
// 	int		i;
// 	char	*str;
// 	char	*tmp;
//
// 	i = -1;
// 	str = NULL;
// 	if (!wc)
// 		return (NULL);
// 	while (wc[++i])
// 	{
// 		if (!str)
// 			str = ft_wchartostr(wc[i]);
// 		else
// 		{
// 			tmp = ft_strjoin(str, ft_wchartostr(wc[i]));
// 			ft_strdel(&str);
// 			str = tmp;
// 		}
// 	}
// 	return (str);
// }

char		*ft_wchartostr(wchar_t chr, int *size)
{
	char	*str;

	if (chr <= 0x7F && (*size = 1))
		return (ft_strchar((char)chr));
	else if (chr <= 0x7FF && (str = try_malloc(sizeof(char) * (3 + 1), _FL_)) && (*size = 2))
	{
		str[0] = ((chr >> 6) + 0xC0);
		str[1] = ((chr & 0x3F) + 0x80);
		str[2] = 0;
	}
	else if (chr <= 0xFFFF && (str = try_malloc(sizeof(char) * (4 + 1), _FL_)) && (*size = 3))
	{
		str[0] = ((chr >> 12) + 0xE0);
		str[1] = (((chr >> 6) & 0x3F) + 0x80);
		str[2] = ((chr & 0x3F) + 0x80);
		str[3] = 0;
	}
	else if (chr <= 0x10FFFF && (str = try_malloc(sizeof(char) * (5 + 1), _FL_)) && (*size = 4))
	{
		str[0] = ((chr >> 18) + 0xF0);
		str[1] = (((chr >> 12) & 0x3F) + 0x80);
		str[2] = (((chr >> 6) & 0x3F) + 0x80);
		str[3] = ((chr & 0x3F) + 0x80);
		str[4] = 0;
	}
	return (str);
}
