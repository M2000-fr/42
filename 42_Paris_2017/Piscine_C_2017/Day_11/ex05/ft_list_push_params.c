/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:19:52 by maechard          #+#    #+#             */
/*   Updated: 2017/03/29 19:26:37 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list		*update2;

	update2 = ft_create_elem(data);
	if (*begin_list)
		update2->next = *begin_list;
	*begin_list = update2;
}

t_list	*ft_list_push_params(int ac, char **av);
{
	t_list		*param;
	int			address;

	address = 0;
	param = NULL;
	while (address < ac)
	{
		ft_list_push_front(&param, av[1]);
		address++;
	}
	return (param);
}
