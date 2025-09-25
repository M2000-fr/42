/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 18:26:44 by mechard           #+#    #+#             */
/*   Updated: 2023/08/06 16:39:33 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
{
	int	add;

	add = 0;
	while (((str[add] >= 'a' && str[add] <= 'z') || (str[add] >= 'A'
				&& str[add] <= 'Z')) && str[add] != '\0')
		add++;
	if (str[add] == '\0')
		return (1);
	return (0);
}
