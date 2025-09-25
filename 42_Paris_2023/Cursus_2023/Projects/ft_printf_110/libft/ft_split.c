/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:19:43 by mechard           #+#    #+#             */
/*   Updated: 2023/12/11 19:51:16 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_word(const char *str, char c)
{
	int	count;
	int	x;

	count = 0;
	x = 0;
	while (*str)
	{
		if (*str != c && x == 0)
		{
			x = 1;
			count++;
		}
		else if (*str == c)
			x = 0;
		str++;
	}
	return (count);
}

void	ft_strdel(char **ap)
{
	int	i;

	i = -1;
	while (ap[++i])
		free(ap[i]);
	free(ap);
}

char	*get_next_word(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (ft_substr(s, 0, len));
}

char	**ft_split(const char *s, char c)
{
	char	**res;
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	res = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!res)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			res[i++] = get_next_word(s, c);
			if (!res[i - 1])
				return (ft_strdel(res), NULL);
			while (*s && *s != c)
				s++;
		}
	}
	res[i] = 0;
	return (res);
}
