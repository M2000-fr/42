/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_heredoc_tools.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:08:27 by mafritz           #+#    #+#             */
/*   Updated: 2025/03/24 17:57:44 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_file_name(void)
{
	char		*name;
	char		*nbr;
	static int	i;

	i = 0;
	nbr = ft_itoa(i);
	if (!nbr)
		return (NULL);
	name = ft_strjoin(HEREDOC_NAME, nbr);
	free(nbr);
	i++;
	return (name);
}

char	*get_delim(char *delim)
{
	int	len;

	len = ft_strlen(delim) - 1;
	if ((delim[0] == '\"' && delim[len] == '\"')
		|| (delim[0] == '\'' && delim[len] == '\''))
		return (ft_strtrim(delim, "\'\""));
	return (ft_strdup(delim));
}

int	no_str_found(t_token	*token)
{
	int	error;

	error = EXIT_FAILURE;
	if (!token->str)
		return (print_token_err("<<", error));
	else if (!token->next)
		return (print_token_err("newline", error));
	else if (token->next->type != TOK_TEXT)
		return (print_token_err(token->next->str, error));
	return (0);
}
