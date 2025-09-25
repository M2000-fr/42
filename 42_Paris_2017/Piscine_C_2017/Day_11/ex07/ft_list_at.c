/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 19:21:22 by maechard          #+#    #+#             */
/*   Updated: 2017/03/29 19:25:03 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list		*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	nb;

	if (!(begin_list))
		return (NULL);
	i = 1;
	while (i < nbr && begin_list->next)
	{
		begin_list = begin_list->next;
		nb++;
	}
	if (nb == nbr)
		return (begin_list);
	else
		return (NULL);
}
