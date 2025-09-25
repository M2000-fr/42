/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/10 19:55:29 by maechard          #+#    #+#             */
/*   Updated: 2017/04/10 20:54:39 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		a;

	a = 0;
	while (str[a] != '\0')
		ft_putchar(str[a++]);
}

int		main(int ac, char **av)
{
	int		fd;
	int		ret;
	char	*buffer[2048];

	if (ac == 1)
	{
		ft_putstr("File name missing.\n");
		return (2);
	}
	if (ac == 2)
	{
		if ((fd = open(av[1], O_RDONLY)) == -1)
			return (2);
		while ((ret = read(fd, buffer, 1024)) > 0)
			write(1, buffer, ret);
		if (close(fd) == -1)
			return (2);
	}
	if (ac > 2)
	{
		ft_putstr("Too many arguments.\n");
		return (2);
	}
	return (0);
}
