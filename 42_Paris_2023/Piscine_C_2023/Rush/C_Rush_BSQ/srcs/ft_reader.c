/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 04:47:06 by ade-rese          #+#    #+#             */
/*   Updated: 2023/08/22 14:14:32 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

char	*ft_next(char *str)
{
	int		i;
	int		j;
	char	*buff;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		return (ft_free_string(str));
	buff = malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!buff)
		return (ft_free_string(str));
	j = i + 1;
	i = 0;
	while (str[j])
		buff[i++] = str[j++];
	buff[i] = '\0';
	return (free(str), buff);
}

char	*ft_reader(int fd)
{
	static char	*line[1024];
	char		*buff;
	char		*res;
	int			nbytes;

	nbytes = 1;
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (nbytes && !ft_is_new_line(line[fd]))
	{
		nbytes = read(fd, buff, BUFFER_SIZE);
		if (nbytes == -1)
			return (ft_free_string(buff));
		buff[nbytes] = '\0';
		line[fd] = ft_strjoin(line[fd], buff);
		if (!line[fd])
			return (ft_free_string(buff));
	}
	res = ft_get_line(line[fd]);
	line[fd] = ft_next(line[fd]);
	return (free(buff), res);
}
