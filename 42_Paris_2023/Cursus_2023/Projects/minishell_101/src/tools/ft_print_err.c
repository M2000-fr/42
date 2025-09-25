/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_err.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:57:08 by mafritz           #+#    #+#             */
/*   Updated: 2025/01/26 13:41:37 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	print_err(char *msg_prefix, char *msg, int ret)
{
	ft_puterr("minishell: ");
	if (msg_prefix)
	{
		if (ft_strcmp(msg_prefix, "\'") && ft_strcmp(msg_prefix, "\""))
			ft_puterr(msg_prefix);
		ft_puterr(": ");
	}
	ft_puterr(msg);
	ft_puterr("\n");
	return (ret);
}

int	print_token_err(char *token, int error)
{
	ft_puterr("minishell: ");
	ft_puterr("syntax error near unexpected token `");
	ft_puterr(token);
	ft_puterr("'");
	ft_puterr("\n");
	return (error);
}

int	print_err_quote_msg(char *msg_prefix, char *msg, int ret)
{
	ft_puterr("minishell: ");
	ft_puterr(msg_prefix);
	ft_puterr(" `");
	ft_puterr(msg);
	ft_puterr("'");
	ft_puterr("\n");
	return (ret);
}

int	print_errno(char *msg_suffix, int ret)
{
	return (print_err(msg_suffix, strerror(errno), ret));
}

void	print_invalid_token_msg(char *str, int i)
{
	char	*token;
	int		len;

	token = extract_invalid_token(str, i);
	len = ft_strlen(token);
	if (!ft_strncmp(token, ">>", 2) || !ft_strncmp(token, "<<", 2)
		|| !ft_strncmp(token, "<", 1))
		(free(token), token = extract_invalid_token(str, i + len));
	print_err_quote_msg("syntax error near unexpected token", token, 2);
	free(token);
}
