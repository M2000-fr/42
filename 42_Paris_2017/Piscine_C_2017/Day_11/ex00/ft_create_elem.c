/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 17:41:54 by maechard          #+#    #+#             */
/*   Updated: 2017/03/29 19:25:36 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

t_list		*ft_create_elem(void *data)
{
	t_list		*chaine;

	if (!(chaine = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (chaine)
	{
		chaine->data = data;
		tmp->next = list;
	}
	return (0)
}
