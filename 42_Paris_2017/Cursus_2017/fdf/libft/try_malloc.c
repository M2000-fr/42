/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_malloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 12:09:53 by tarchen           #+#    #+#             */
/*   Updated: 2017/09/27 09:08:31 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void		*try_malloc(size_t size, char *f, int l)
{
	void	*alloc;

	if (!(alloc = ft_memalloc(size)))
	{
		ft_putstr_fd("error: malloc can't allocate region in: \033[31;01m", 2);
		ft_putstr_fd(f, 2);
		ft_putstr_fd("\033[0m - (line:\033[35;01m", 2);
		ft_putnbr_fd(l, 2);
		ft_putstr_fd("\033[0m)\n", 2);
		exit(1);
	}
	return (alloc);
}

void		*try_malloc_i(size_t size, int init, char *f, int l)
{
	void	*alloc;

	if (!(alloc = ft_memalloc_i(size, init)))
	{
		ft_putstr_fd("error: malloc can't allocate region in: \033[31;01m", 2);
		ft_putstr_fd(f, 2);
		ft_putstr_fd("\033[0m - (line:\033[35;01m", 2);
		ft_putnbr_fd(l, 2);
		ft_putstr_fd("\033[0m)\n", 2);
		exit(1);
	}
	return (alloc);
}

void		*try_malloc_sp(size_t size, char *f, int l)
{
	void	*alloc;

	if (!(alloc = ft_memalloc_sp(size)))
	{
		ft_putstr_fd("error: malloc can't allocate region in: \033[31;01m", 2);
		ft_putstr_fd(f, 2);
		ft_putstr_fd("\033[0m - (line:\033[35;01m", 2);
		ft_putnbr_fd(l, 2);
		ft_putstr_fd("\033[0m)\n", 2);
		exit(1);
	}
	return (alloc);
}

void		*try_alloca(size_t size, char *f, int l)
{
	void	*alloc;

	if (!(alloc = ft_memalloca(size)))
	{
		ft_putstr_fd("error: alloca can't allocate region in: \033[31;01m", 2);
		ft_putstr_fd(f, 2);
		ft_putstr_fd("\033[0m - (line:\033[35;01m", 2);
		ft_putnbr_fd(l, 2);
		ft_putstr_fd("\033[0m)\n", 2);
		exit(1);
	}
	return (alloc);
}
