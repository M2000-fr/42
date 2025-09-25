/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:13:14 by mechard           #+#    #+#             */
/*   Updated: 2025/01/23 15:27:13 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
	{
		if (write(fd, s, ft_strlen(s)) == -1)
			write(2, "write error: No space left on device\n", 37);
	}
}

void	ft_putstr_libft(char *s)
{
	if (s)
	{
		if (write(1, s, ft_strlen(s)) == -1)
			write(2, "write error: No space left on device\n", 37);
	}
}
