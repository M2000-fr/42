/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 03:47:36 by maechard          #+#    #+#             */
/*   Updated: 2017/11/27 03:47:38 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft/includes/libft.h"

typedef	struct			s_printf
{
	char		*str;
	int			i;
	int			f;
	int			start;
	char		*ret;
	long		len;
	long		len_flag;
	size_t		nbr;
	float		nb;
	int			c;
	double		e;
	long		prec;
	int			eE;
	wchar_t		Ch;
	wchar_t		*St;
}						t_printf;

typedef void			(*t_func)(va_list aq, t_printf *tab);

void					ft_flags(va_list aq, t_printf *tab);
void					ft_flagc(va_list aq, t_printf *tab);
void					Intonchar(t_printf *tab);
void					ft_flagdDi(va_list aq, t_printf *tab);
void					Pwronchar(int pwr, t_printf *tab);
char					*Dblonchar(t_printf *tab, char *str);
void					Dbl(t_printf *tab);
void					ft_flage(va_list aq, t_printf *tab);
long					ft_power(int pow, int n);
void					Dbloncharf(t_printf *tab);
void					ft_flagf(va_list aq, t_printf *tab);
void					ft_flagxX(va_list aq, t_printf *tab);
void					ft_flagoO(va_list aq, t_printf *tab);
void					ft_prcent(va_list aq, t_printf *tab);
void					ft_flagC(va_list aq, t_printf *tab);
void					ft_flagS(va_list aq, t_printf *tab);
void       			    ft_flagp(va_list aq, t_printf *tab);
int						ft_printf(const char *format, ...);

#endif	