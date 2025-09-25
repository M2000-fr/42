/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftl_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 09:25:22 by maechard          #+#    #+#             */
/*   Updated: 2018/08/06 09:25:29 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ftl.h"

void	ft_exit(void)
{
	exit(1);
}

void	ft_malloc_error(void)
{
	ft_putstr_fd("malloc error\n", 2);
	ft_exit();
}

void	ft_error_str(char *str)
{
	ft_putstr_fd(str, 2);
}

void	ft_error_str_exit(char *str)
{
	ft_putstr_fd(str, 2);
	ft_exit();
}
