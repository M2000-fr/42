/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:00:06 by tarchen           #+#    #+#             */
/*   Updated: 2017/09/27 09:08:59 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	*ft_memalloc(size_t size)
{
	void	*area_allocated;

	area_allocated = malloc(size);
	if (area_allocated)
		area_allocated = ft_memset(area_allocated, 0, size);
	return (area_allocated);
}

void	*ft_memalloc_i(size_t size, int init)
{
	void	*area_allocated;

	area_allocated = malloc(size);
	if (area_allocated)
		area_allocated = ft_memset(area_allocated, init, size);
	return (area_allocated);
}


void	*ft_memalloc_sp(size_t size)
{
	void	*area_allocated;

	area_allocated = malloc(size);
	if (area_allocated)
		area_allocated = ft_memset(area_allocated, ' ', size);
	return (area_allocated);
}

void	*ft_memalloca(size_t size)
{
	void	*area_allocated;

	area_allocated = alloca(size);
	if (area_allocated)
		area_allocated = ft_memset(area_allocated, 0, size);
	return (area_allocated);
}
