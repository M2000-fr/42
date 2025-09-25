/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dstrncpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 13:05:45 by mechard           #+#    #+#             */
/*   Updated: 2024/10/14 15:14:51 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_dstrncpy(char **dstr, int sub, int flag)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_dstrlen(dstr) - sub;
	str = "/";
	if (flag == 0)
	{
		while (i < len - 1)
		{
			str = ft_strjoin(str, dstr[i++]);
			str = ft_strjoin(str, "/");
		}
		str = ft_strjoin(str, dstr[i]);
	}
	if (flag == 1)
	{
		while (i < len)
		{
			str = ft_strjoin(str, dstr[i++]);
			str = ft_strjoin(str, "/");
		}
	}
	return (str);
}

char	*ft_dstrscpy(char **dstr, int start, int sub, int flag)
{
	int		i;
	int		len;
	char	*str;

	i = start;
	len = ft_dstrlen(dstr) - sub;
	str = "/";
	if (flag == 0)
	{
		while (i < len - 1)
		{
			str = ft_strjoin(str, dstr[i++]);
			str = ft_strjoin(str, "/");
		}
		str = ft_strjoin(str, dstr[i]);
	}
	if (flag == 1)
	{
		while (i < len)
		{
			str = ft_strjoin(str, dstr[i++]);
			str = ft_strjoin(str, "/");
		}
	}
	return (str);
}

char	*ft_dstrcpy(char **dstr, int sub, int flag)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	len = ft_dstrlen(dstr) - sub;
	str = "/";
	if (flag == 0)
	{
		while (dstr[i])
		{
			str = ft_strjoin(str, dstr[i++]);
			str = ft_strjoin(str, "/");
		}
		str = ft_strjoin(str, dstr[i]);
	}
	if (flag == 1)
	{
		while (dstr[i])
		{
			str = ft_strjoin(str, dstr[i++]);
			str = ft_strjoin(str, "/");
		}
	}
	return (str);
}
