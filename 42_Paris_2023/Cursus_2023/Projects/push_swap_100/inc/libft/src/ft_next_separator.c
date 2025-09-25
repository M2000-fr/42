/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_next_separator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 19:19:31 by mechard           #+#    #+#             */
/*   Updated: 2024/03/27 09:55:15 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_next_separator(int i, const char *str, char charset)
{
	int	count;

	count = 0;
	while (str[i])
	{
		if (charset == str[i])
			return (count);
		count++;
		i++;
	}
	if (str[i] == '\0')
		return (count);
	return (0);
}
