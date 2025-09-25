/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:20:26 by mechard           #+#    #+#             */
/*   Updated: 2024/11/07 10:55:14 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdstr_fd(char **str, int fd)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			ft_putstr_fd(str[i++], fd);
	}
	return ;
}
