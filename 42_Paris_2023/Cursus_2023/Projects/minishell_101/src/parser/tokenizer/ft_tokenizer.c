/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenizer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 11:03:08 by mechard           #+#    #+#             */
/*   Updated: 2025/01/21 14:48:45 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*interpolate_result(t_interpolator *c, t_status *s, int quote)
{
	if (quote && is_quote(**(c->str)))
	{
		if (update_quote_status(**(c->str), c->str, s))
		{
			if (!ft_strlen(c->res))
				c->shell->flag = EMPTY_STR;
			return (c->res);
		}
	}
	if (**(c->str) == '$' && *s != STATUS_IN_QUOTES)
	{
		c->res = add_var_value(c);
		if (c->res && *s != STATUS_IN_DQUOTES)
			c->shell->flag = IS_VARIABLE;
	}
	else
	{
		if (**(c->str) == '\\' && *(*(c->str) + 1) == '$' && not_in_quotes(s))
			++(*(c->str));
		c->res = add_char_to_buff(c->res, c->res_i, c->len, **(c->str));
		if (*(c->str))
			++(*(c->str));
	}
	return (c->res);
}

char	*interpolate_variables(t_minishell *shell, char *str, int quote)
{
	t_interpolator	ctx;
	t_status		status;
	char			*result;
	int				buffer_len;
	int				res_i;

	buffer_len = 256;
	res_i = 0;
	result = allocate_empty_string(buffer_len);
	status = init_quote_status();
	ctx.shell = shell;
	ctx.str = &str;
	ctx.res = result;
	ctx.res_i = &res_i;
	ctx.len = &buffer_len;
	while (*str)
	{
		result = interpolate_result(&ctx, &status, quote);
		if (ctx.shell->flag != 0)
			shell->flag = ctx.shell->flag;
		if (!result)
			return (NULL);
	}
	return (add_char_to_buff(result, &res_i, &buffer_len, '\0'));
}

void	interpolate_token(t_minishell *shell, t_token *token)
{
	char	*interpolated_str;

	if (!token)
		return ;
	if (token->type == TOK_SQUOTE_TEXT || token->type == TOK_DQUOTE_TEXT)
		return ;
	interpolated_str = interpolate_variables(shell, token->str, 1);
	free(token->str);
	token->str = interpolated_str;
}

void	interpolator(t_minishell *shell, t_token *token_list)
{
	t_token	*current_token;

	if (!token_list)
		return ;
	current_token = token_list;
	while (current_token)
	{
		interpolate_token(shell, current_token);
		current_token = current_token->next;
	}
}

t_token_line	ft_tokenizer(t_minishell *shell, char *raw_str)
{
	t_token_line	token_line;
	int				i;

	token_line = init_token_line();
	i = 0;
	while (raw_str[i])
	{
		i = extract_next_token(raw_str, &token_line, i);
		if (i == -1)
		{
			token_line.status = STATUS_ERR;
			return (token_line);
		}
	}
	check_status(&token_line);
	if (token_line.status != STATUS_OK)
		return (token_line);
	interpolator(shell, token_line.token_list);
	return (token_line);
}
