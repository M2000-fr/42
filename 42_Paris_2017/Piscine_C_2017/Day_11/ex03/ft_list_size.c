/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:13:50 by maechard          #+#    #+#             */
/*   Updated: 2017/03/29 19:26:00 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_list.h>

void	ft_list_push_front(t_list **begin_list, void *data)
{
	int		length;

	length = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		length++;
	}
	return (length);
}
