/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:31:48 by mechard           #+#    #+#             */
/*   Updated: 2024/03/04 11:41:34 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include "get_next_line.h"
# include <stdarg.h>

# define UINT_PERSO_MAX 4294967295
# define INT_PERSO_MAX 2147483647
# define INT_PERSO_MIN -2147483648

int		ft_printf(const char *s, ...);
int		ft_check_mand(char *str, va_list args, int *len);
int		ft_check_bonu(char *str, va_list args, int *len);
int		ft_parse(char *str, va_list args, int *len);

void	ft_putnbr_unsigned(unsigned int nb, int *len);
void	ft_putnbr(int nb, int *len);
void	ft_putchar(char c, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putnbr_base(unsigned long long nbr, char *base, int *len, char c);

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);

char	*ft_strdup(const char *s);

#endif
