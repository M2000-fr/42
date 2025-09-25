/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 08:49:12 by mechard           #+#    #+#             */
/*   Updated: 2023/12/11 19:33:38 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_next_line(char *str)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (free(str), NULL);
	buff = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!buff)
		return (free(str), NULL);
	j = i + 1;
	i = 0;
	while (str[j])
		buff[i++] = str[j++];
	buff[i] = '\0';
	return (free(str), buff);
}

char	*get_next_line(int fd)
{
	static char	*line;
	char		*buff;
	char		*res;
	int			nbytes;

	nbytes = 1;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (nbytes && !ft_new_line(line))
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes == -1)
			return (free(buff), NULL);
		buff[nbytes] = '\0';
		line = ft_strjoin(line, buff);
		if (!line)
			return (free(buff), NULL);
	}
	res = ft_get_line(line);
	line = ft_next_line(line);
	return (free(buff), res);
}
