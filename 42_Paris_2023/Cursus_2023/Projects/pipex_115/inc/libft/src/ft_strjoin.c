/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:48:43 by mechard           #+#    #+#             */
/*   Updated: 2024/03/04 11:07:48 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
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
	return (r);
}
