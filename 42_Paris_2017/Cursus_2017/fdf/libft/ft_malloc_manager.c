/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_manager.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 04:18:14 by tarchen           #+#    #+#             */
/*   Updated: 2017/06/26 07:09:03 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../../libft/includes/libft.h"

t_mam				*mam(void *ap, size_t size, int opt)
{
	static t_mam	*start_list;
	static t_mam	*current;

	if (!opt)
	{
		if (!current)
			current = try_malloc(sizeof(t_mam), _FL_);
		if (!start_list)
			start_list = current;
		current->ap = ap;
		current->size = size;
		current->next = try_malloc(sizeof(t_mam), _FL_);
		current->next->prev = current;
		current = current->next;
		return (NULL);
	}
	else
		return (start_list);
}

void				*mam_alloc(size_t size, char *f, int l)
{
	void			*ap;

	ap = try_malloc(size, f, l);
	mam(ap, size, 0);
	return (ap);
}

void				mam_free_target(t_mam *tmp, void **ap)
{
	while (tmp)
	{
		if (tmp->ap == *ap)
		{
			ft_memdel(ap);
			tmp->prev->next = tmp->next;
			tmp->next->prev = tmp->prev;
			ft_memdel((void**)&tmp);
			break ;
		}
		tmp = tmp->next;
	}
	return ;
}

void				mam_free(void **ap)
{
	t_mam			*tmp;

	tmp = mam(NULL, 0, 1);
	if (ap && *ap)
	{
		mam_free_target(tmp, ap);
		return ;
	}
	while (tmp->next)
		tmp = tmp->next;
	while (tmp)
	{
		ft_memdel(&tmp->ap);
		tmp = tmp->prev;
		if (tmp)
			ft_memdel((void**)(&tmp->next));
		else
			break ;
	}
}
