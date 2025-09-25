/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 16:56:30 by mechard           #+#    #+#             */
/*   Updated: 2025/01/23 15:23:46 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	if (write(fd, &c, 1) == -1)
		write(2, "write error: No space left on device\n", 37);
}

void	ft_putchar_libft(char c)
{
	if (write(1, &c, 1) == -1)
		write(2, "write error: No space left on device\n", 37);
}
