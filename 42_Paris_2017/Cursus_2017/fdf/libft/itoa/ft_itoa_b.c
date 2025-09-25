/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 00:10:39 by tarchen           #+#    #+#             */
/*   Updated: 2017/09/07 02:29:22 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_itoa.h"

char		*get_val_alpha(va_list ap, char *fmt, int base, char lu)
{
	if (!ft_strcmp(fmt, "char"))
		return (ft_itoa_char((char)va_arg(ap, int), base, lu));
	if (!ft_strcmp(fmt, "unsigned_char"))
		return (\
		ft_itoa_unsigned_char((unsigned char)va_arg(ap, int), base, lu));
	if (!ft_strcmp(fmt, "short"))
		return (ft_itoa_short((short)va_arg(ap, int), base, lu));
	if (!ft_strcmp(fmt, "unsigned_short"))
		return (\
		ft_itoa_unsigned_short((unsigned short)va_arg(ap, int), base, lu));
	if (!ft_strcmp(fmt, "int"))
		return (ft_itoa_int(va_arg(ap, int), base, lu));
	if (!ft_strcmp(fmt, "unsigned"))
		return (ft_itoa_unsigned(va_arg(ap, unsigned), base, lu));
	if (!ft_strcmp(fmt, "long"))
		return (ft_itoa_long(va_arg(ap, long), base, lu));
	if (!ft_strcmp(fmt, "unsigned_long"))
		return (ft_itoa_unsigned_long(va_arg(ap, unsigned long), base, lu));
	if (!ft_strcmp(fmt, "long_long"))
		return (ft_itoa_long_long(va_arg(ap, long long), base, lu));
	else
		return (NULL);
}

char		*get_val_beta(va_list ap, char *fmt, int base, char lu)
{
	if (!ft_strcmp(fmt, "unsigned_long_long"))
		return (ft_itoa_unsigned_long_long(\
		va_arg(ap, unsigned long long), base, lu));
	if (!ft_strcmp(fmt, "float"))
		return (ft_itoa_float((float)va_arg(ap, double), base, lu));
	if (!ft_strcmp(fmt, "double"))
		return (ft_itoa_double(va_arg(ap, double), base, lu));
	if (!ft_strcmp(fmt, "long_double"))
		return (ft_itoa_long_double(va_arg(ap, long double), base, lu));
	if (!ft_strcmp(fmt, "size_t"))
		return (ft_itoa_size_t(va_arg(ap, size_t), base, lu));
	if (!ft_strcmp(fmt, "intptr_t"))
		return (ft_itoa_intptr_t(va_arg(ap, intptr_t), base, lu));
	if (!ft_strcmp(fmt, "uintptr_t"))
		return (ft_itoa_uintptr_t(va_arg(ap, uintptr_t), base, lu));
	if (!ft_strcmp(fmt, "intmax_t"))
		return (ft_itoa_intmax_t(va_arg(ap, intmax_t), base, lu));
	if (!ft_strcmp(fmt, "uintmax_t"))
		return (ft_itoa_uintmax_t(va_arg(ap, uintmax_t), base, lu));
	else
		return (NULL);
}

char		*ft_itoa_b(int base, char lower_upper, char *fmt, ...)
{
	va_list	ap;
	char	*ret;

	va_start(ap, fmt);
	if (!(ret = get_val_alpha(ap, fmt, base, lower_upper)))
		ret = get_val_beta(ap, fmt, base, lower_upper);
	va_end(ap);
	return (ret);
}

char		*ft_itoa_b_ap(int base, char lower_upper, char *fmt, va_list ap)
{
	char	*ret;

	if (!(ret = get_val_alpha(ap, fmt, base, lower_upper)))
		ret = get_val_beta(ap, fmt, base, lower_upper);
	return (ret);
}

char		*ft_itoa_lo(char *fmt, va_list ap)
{
	return(ft_itoa_b_ap(10, LOWER, fmt, ap));
}

char		*ft_itoa_up(char *fmt, va_list ap)
{
	return(ft_itoa_b_ap(10, UPPER, fmt, ap));
}
