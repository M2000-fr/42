/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/22 06:08:45 by tarchen           #+#    #+#             */
/*   Updated: 2017/09/22 06:15:35 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	error(char *msg, int *code_error)
{
	write(2, msg, ft_strlen(msg));
	if (code_error)
		exit (*code_error);
}
