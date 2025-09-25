/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:16:22 by maechard          #+#    #+#             */
/*   Updated: 2017/03/29 19:20:08 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "list.h"

void	ft_list_clear(t_list **begin_list)
{
	t_list		*tmp;

	if (!(*begin_list))
		return ;
	tmp = *begin_list;
	if (tmp->next)
		ft_list_clear(&tmp->next);
	*begin_list = NULL;
	free(tmp);
}
