/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_heredoc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:03:42 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/26 13:03:42 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	open_file(char	*file)
{
	int	fd;

	fd = open(file, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
		print_err(file, "heredoc file error", EXIT_FAILURE);
	return (fd);
}

int	heredoc_handler(t_minishell *shell, char *delim, char *file)
{
	char	*new_line;
	char	*line;
	int		fd;

	fd = open_file(file);
	while (1)
	{
		active_user_input();
		line = readline("heredoc> ");
		deactivate_active_input();
		if (ctrl_d_handling(line, "Warning: heredoc terminated by EOF"))
			break ;
		if (ft_strcmp(line, delim) == 0)
			break ;
		new_line = interpolate_variables(shell, line, 0);
		ft_putendl_fd(new_line, fd);
		free(line);
		free(new_line);
	}
	free(line);
	close(fd);
	return (EXIT_SUCCESS);
}

void	set_up_heredoc(t_minishell	*s, t_cmd	*cmd, t_token	*t)
{
	char	*delim;
	char	*file;
	int		fd_tmp;

	delim = get_delim(t->next->str);
	file = get_file_name();
	if (heredoc_handler(s, delim, file) == EXIT_SUCCESS)
	{
		if (file)
		{
			fd_tmp = open(file, O_RDONLY);
			if (cmd->file_redir.infile)
				free(cmd->file_redir.infile);
			cmd->file_redir.infile = file;
			cmd->file_redir.intype = REDIR_IN_FILE;
			close(fd_tmp);
		}
	}
	free(delim);
}

t_token	*ft_parse_heredoc(t_minishell	*s, t_cmd **cmd_head, t_token	*t)
{
	t_token	*tmp;
	t_cmd	*cmd;

	tmp = t;
	if (no_str_found(tmp))
	{
		ft_cfree(*cmd_head);
		*cmd_head = NULL;
		return (NULL);
	}
	cmd = get_last_cmd(*cmd_head);
	if (!cmd)
	{
		cmd = add_cmd(cmd_head);
	}
	set_up_heredoc(s, cmd, tmp);
	return (tmp->next);
}
