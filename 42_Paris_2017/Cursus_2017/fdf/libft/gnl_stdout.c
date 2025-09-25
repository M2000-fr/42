/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_stdout.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Theo <Theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 01:16:28 by Theo              #+#    #+#             */
/*   Updated: 2017/11/29 09:37:29 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

static int		ft_strrep(char **line, char *str)
{
	*line = ft_strdup(str);
	ft_strdel(&str);
	return (0);
}

static int		ft_strlen_line(char **line, char **str, int n)
{
	n = ft_strchr(*str, '\n') - *str;
	*line = ft_strsub(*str, 0, n);
	*str = ft_strsub(*str, n + 1, ft_strlen(*str) - n - 1);
	return (1);
}

int				gnl_stdout(char **line)
{
	dprintf(3, "%s (%d)\n", _FL_);
	int			n;
	int			ret;
	char		buf[BUFF_SIZE + 1];
	static char	*str = NULL;

	dprintf(3, "%s (%d)\n", _FL_);
	n = 0;
	dprintf(3, "%s (%d)\n", _FL_);
	while (!str || !ft_strchr(str, '\n'))
	{
		dprintf(3, "%s (%d)\n", _FL_);
		if ((ret = read(0, buf, BUFF_SIZE)) < 0)
			return (-1);
		buf[ret] = '\0';
		if (ret == 0)
		{
			dprintf(3, "%s (%d)\n", _FL_);
			return (str != NULL ? ft_strrep(line, str) : 0);
		}
		if (str != NULL)
			str = ft_strjoin(str, buf);
		else
			str = ft_strdup(buf);
		dprintf(3, "%s (%d)\n", _FL_);
	}
	dprintf(3, "%s (%d)\n", _FL_);
	return (!str ? 0 : ft_strlen_line(line, &str, n));
}
