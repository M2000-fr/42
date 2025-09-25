/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:31:17 by mechard           #+#    #+#             */
/*   Updated: 2024/04/19 15:08:15 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check(char *str, int i, va_list args, int *len)
{
	char	*flags;
	char	*bonus;
	int		fm;
	int		fb;

	fm = 0;
	bonus = "# +";
	flags = "cdipPsuxX%";
	while (flags[fm])
	{
		if (str[i] == flags[fm])
			return (ft_check_mand(str + i, args, len) + i);
		fm++;
	}
	fb = 0;
	while (bonus[fb])
	{
		if (str[i] == bonus[fb] || ft_isdigit(str[i]) == 1)
			return (ft_check_bonu(str + i, args, len) + i);
		fb++;
	}
	return (0);
}

int	ft_parse(char *str, va_list args, int *len)
{
	int	nb_space;
	int	i;

	i = 1;
	nb_space = 0;
	if (ft_isdigit(str[i]) == 1)
		nb_space = ft_atoi(str + i);
	if (nb_space > 0)
		i += ft_nbrlen(nb_space, 10);
	while (nb_space > 0)
	{
		ft_putchar(' ', len);
		nb_space--;
	}
	return (ft_check(str, i, args, len));
}

int	ft_printf(const char *s, ...)
{
	size_t	i;
	va_list	args;
	char	*str;
	int		len;

	str = ft_strdup(s);
	if (!str)
		return (0);
	va_start(args, s);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
			i += ft_parse(str + i, args, &len);
		else
			ft_putchar(str[i], &len);
		i++;
	}
	free(str);
	return (len);
}
