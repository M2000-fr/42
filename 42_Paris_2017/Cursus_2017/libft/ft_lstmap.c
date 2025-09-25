/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 04:34:46 by maechard          #+#    #+#             */
/*   Updated: 2017/04/28 11:57:07 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*res;
	t_list	*res_befo;

	res_befo = f(lst);
	res = res_befo;
	if (res == NULL || !(lst))
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		res_befo->next = f(lst);
		if (res_befo->next == NULL)
			return (NULL);
		res_befo = res_befo->next;
	}
	return (res_befo);
}
