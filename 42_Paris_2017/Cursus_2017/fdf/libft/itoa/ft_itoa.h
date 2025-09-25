/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tarchen <tarchen@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 09:55:57 by tarchen           #+#    #+#             */
/*   Updated: 2017/09/07 02:28:59 by tarchen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ITOA_H
# define FT_ITOA_H
# include "../includes/libft.h"
# include <stdint.h>
# define UPPER 0
# define LOWER 1

char	*ft_itoa_lo(char *fmt, va_list ap);
char	*ft_itoa_up(char *fmt, va_list ap);
char	*ft_itoa_b(int base, char lower_upper, char *fmt, ...);
char	*ft_itoa_b_ap(int base, char lower_upper, char *fmt, va_list ap);
char	*ft_itoa_char(char val, int base, char lu);
char	*ft_itoa_long_long(long long val, int base, char lu);
char	*ft_itoa_double(double f, int base, char lu, size_t len);
char	*ft_itoa_float(float f, int base, char lu);
char	*ft_itoa_int(int val, int base, char lu);
char	*ft_itoa_intmax_t(intmax_t val, int base, char lu);
char	*ft_itoa_intptr_t(intptr_t val, int base, char lu);
char	*ft_itoa_long(long val, int base, char lu);
char	*ft_itoa_long_double(long double f, int base, char lu);
char	*ft_itoa_short(short val, int base, char lu);
char	*ft_itoa_size_t(size_t val, int base, char lu);
char	*ft_itoa_uintmax_t(uintmax_t val, int base, char lu);
char	*ft_itoa_uintptr_t(uintptr_t val, int base, char lu);
char	*ft_itoa_unsigned(unsigned val, int base, char lu);
char	*ft_itoa_unsigned_char(unsigned char val, int base, char lu);
char	*ft_itoa_unsigned_long(unsigned long val, int base, char lu);
char	*ft_itoa_unsigned_long_long(unsigned long long val, int base, char lu);
char	*ft_itoa_unsigned_short(unsigned short val, int base, char lu);
#endif