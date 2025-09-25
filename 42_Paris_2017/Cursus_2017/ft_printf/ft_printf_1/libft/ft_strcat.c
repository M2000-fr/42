/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 12:59:34 by tarchen           #+#    #+#             */
/*   Updated: 2016/11/09 14:48:07 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	char	*ret;

	ret = s1;
	while (*s1)
		s1++;
	ft_strcpy(s1, s2);
	return (ret);
}
