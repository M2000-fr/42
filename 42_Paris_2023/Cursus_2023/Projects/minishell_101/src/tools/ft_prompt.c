/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:53:10 by mechard           #+#    #+#             */
/*   Updated: 2025/01/26 15:19:08 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*create_folder(char	*name, char	*hour,	char *folder,	char	*arrow)
{
	char	*current_folder;
	char	*tmp;
	char	*tmp1;
	char	*tmp2;

	tmp = ft_strjoin(name, hour);
	tmp1 = ft_strjoin(tmp, " ");
	tmp2 = ft_strjoin(folder, arrow);
	current_folder = ft_strjoin(tmp1, tmp2);
	free(folder);
	free(name);
	free(hour);
	free(arrow);
	free(tmp);
	free(tmp1);
	free(tmp2);
	return (current_folder);
}

char	*create_prompt(char	**path, char	*current_hour)
{
	char	*current_folder;
	char	*folder;
	char	*name;
	char	*arrow;

	arrow = ft_strdup(" $>");
	name = ft_strdup("{\001\033[32m\002minishell\001\033[0m\002-");
	if (!name || !arrow)
		return (NULL);
	folder = ft_strdup(path[ft_dstrlen(path) - 1]);
	current_folder = create_folder(name, current_hour, folder, arrow);
	return (current_folder);
}

char	*ft_prompt(void)
{
	char	**path;
	char	*current_hour;
	char	*prompt;
	char	*cwd;

	cwd = getcwd(NULL, 0);
	current_hour = get_current_time();
	if (!ft_strncmp("/\0", cwd, 2))
		path = ft_split("/", ' ');
	else if (cwd)
		path = ft_split(cwd, '/');
	else
		path = ft_split("ERROR", '/');
	free(cwd);
	prompt = create_prompt(path, current_hour);
	ft_dfree(path);
	if (!prompt)
		return ("ERROR");
	return (prompt);
}

char	*custom_readline(char *prompt)
{
	char	*input;

	input = readline(prompt);
	if (input && *input)
		add_history(input);
	return (input);
}
