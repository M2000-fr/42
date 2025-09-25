/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:59:14 by mechard           #+#    #+#             */
/*   Updated: 2024/07/08 13:16:41 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_init(t_pipex *pipex, int ac, char **av, char **env)
{
	if (ft_read_user(av[1], av[2]) == 0)
		init_pipex_no_hd(pipex, ac, av, env);
	else
		init_pipex_w_hd(pipex, ac, av, env);
}

void	init_pipex_w_hd(t_pipex *pipex, int ac, char **av, char **env)
{
	pipex->env = env;
	pipex->outfile = av[ac - 1];
	pipex->path = get_env_path(env);
	pipex->prev_pipe = -1;
	pipex->size = ac - 4;
	pipex->infile = av[2];
	pipex->j = 3;
}

void	init_pipex_no_hd(t_pipex *pipex, int ac, char **av, char **env)
{
	pipex->env = env;
	pipex->outfile = av[ac - 1];
	pipex->path = get_env_path(env);
	pipex->prev_pipe = -1;
	pipex->size = ac - 3;
	pipex->infile = av[1];
	pipex->j = 2;
}

char	*ft_reader(char *av2, char *res)
{
	char	*tmp;

	tmp = ft_calloc(1, sizeof(char));
	if (!tmp)
		return (NULL);
	while (tmp)
	{
		write(1, "> ", 2);
		free(tmp);
		tmp = get_next_line(0);
		if (ft_strncmp(av2, tmp, ft_strlen(av2)) != 0)
			res = ft_strjoin_gnl(res, tmp);
		else
			break ;
	}
	free(tmp);
	get_next_line(-1);
	return (res);
}

int	ft_read_user(char *av1, char *av2)
{
	int		i;
	int		hd;
	size_t	reader;
	char	*res;

	i = 0;
	res = NULL;
	reader = 0;
	hd = open(av1, O_RDONLY);
	if (ft_strncmp(av1, "here_doc", ft_strlen("here_doc")) == 0 && (hd < 0
			|| hd > 1024 || read(hd, 0, 0) < 0))
	{
		if (hd > 0)
			close(hd);
		hd = open(av2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (hd < 0 || hd > 1024 || read(hd, 0, 0) < 0)
			res = ft_reader(av2, res);
		else
			return (1);
		if (res && write(hd, res, ft_strlen(res)) == -1)
			return (close(hd), perror("Erreur d'écriture dans le fichier"), 1);
		return (free(res), close(hd), 1);
	}
	else
		return (close(hd), 0);
}
