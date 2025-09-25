/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 17:50:50 by maechard          #+#    #+#             */
/*   Updated: 2017/03/29 19:25:18 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list		*update;
	t_list		*exist;

	exixt = *begin_list
	update = ft_create_elem(data);
	if (!(exist))
		*begin_list = update;
	else
	{
		while (exist->next)
			exist = exist->next;
		exist->next = update;
	}
}
