/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:28:26 by mechard           #+#    #+#             */
/*   Updated: 2024/03/04 11:08:55 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_gnl(char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	s_len;
	char	*r;

	if (!s1 && !s2)
		return (ft_strdup(""));
	if (s1 && !s2)
		return (ft_strdup(s1));
	if (!s1 && s2)
		return (ft_strdup(s2));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s_len = s1_len + s2_len + 1;
	r = malloc(sizeof(char) * s_len);
	if (!r)
		return (0);
	ft_memmove(r, (void *)s1, s1_len);
	ft_memmove(r + s1_len, (void *)s2, s2_len);
	r[s_len - 1] = '\0';
	return (free(s1), r);
}

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_new_line(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == '\n')
				return (1);
			i++;
		}
	}
	return (0);
}

char	*ft_get_line(char *str)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	j = 0;
	if (!str || !str[0])
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	buff = malloc(sizeof(char) * (i + 2));
	if (!buff)
		return (0);
	while (j <= i)
	{
		buff[j] = str[j];
		j++;
	}
	buff[j] = '\0';
	return (buff);
}
