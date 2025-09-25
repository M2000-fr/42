/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_pipex_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 13:59:14 by mechard           #+#    #+#             */
/*   Updated: 2024/12/30 11:43:22 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pipex_print_error(char *name, char *str)
{
	ft_putstr_fd(name, 2);
	ft_putstr_fd(str, 2);
	ft_putstr_fd(": command not found\n", 2);
}
