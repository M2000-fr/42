/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/16 03:20:01 by maechard          #+#    #+#             */
/*   Updated: 2017/04/16 04:18:54 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*chaine;

	if (!alst || !del)
		return ;
	chaine = *alst;
	while (chaine)
	{
		del(chaine->content, chaine->content_size);
		free(chaine);
		chaine = chaine->next;
	}
	*alst = NULL;
}
