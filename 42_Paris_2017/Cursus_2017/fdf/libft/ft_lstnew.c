/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:37:18 by tarchen           #+#    #+#             */
/*   Updated: 2016/11/09 20:37:29 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./includes/libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;
	void	*new_content;

	if (!(new_content = ft_memalloc(content_size + 1)))
		return (NULL);
	if (!content)
	{
		new_content = NULL;
		content_size = 0;
	}
	else
		ft_memcpy(new_content, content, content_size);
	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->content = new_content;
	list->content_size = content_size;
	list->next = NULL;
	return (list);
}
