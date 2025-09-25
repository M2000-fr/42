/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Theo <Theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 08:01:40 by Theo              #+#    #+#             */
/*   Updated: 2017/06/20 19:32:33 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

int			ft_putnbr_lld_base_fd(long int nbr, int base, int fd)
{
	char	*str;

	str = ft_itoa_base_lld(nbr, base);
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}

int			ft_putnbr_base_fd(int nbr, int base, int fd)
{
	char	*str;

	str = ft_itoa_base(nbr, base);
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}

int			ft_putnbr_lld_base(long int nbr, int base)
{
	char	*str;

	str = ft_itoa_base_lld(nbr, base);
	ft_putstr(str);
	return (ft_strlen(str));
}

int			ft_putnbr_base(int nbr, int base)
{
	char	*str;

	str = ft_itoa_base(nbr, base);
	ft_putstr(str);
	return (ft_strlen(str));
}