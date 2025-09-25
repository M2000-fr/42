/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 03:46:55 by maechard          #+#    #+#             */
/*   Updated: 2017/11/27 03:46:57 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf.h"

static const	t_func	g_flag[] =
{
	['d'] = ft_flagdDi,
	['f'] = ft_flagf,
	['F'] = ft_flagf,
//	['a'] = ft_float,
//	['A'] = ft_float,
//	['g'] = ft_float,
//	['G'] = ft_float,
	['e'] = ft_flage,
	['E'] = ft_flage,
	['i'] = ft_flagdDi,
//	['b'] = ft_base,
	['o'] = ft_flagoO,
	['x'] = ft_flagxX,
	['D'] = ft_flagdDi,
	['u'] = ft_flagdDi,
	['U'] = ft_flagdDi,
	['O'] = ft_flagoO,
	['X'] = ft_flagxX,
	['s'] = ft_flags,
	['c'] = ft_flagc,
	['C'] = ft_flagC,
	['p'] = ft_flagp,
	['S'] = ft_flagS,
};

int			find_flag(const char *format, char *flag, t_printf *tab)
{
	int		i;
	int		f;

	i = ft_strlen(format);
	f = 0;
	tab->len_flag = 1;
	while(format[tab->start] != '%' && format[tab->start] != '\0')
		tab->start++;
	i = tab->start;
	while(format[++i] == ' ')
		tab->len_flag++;
	while(format[i] != flag[f] && flag[f] != '\0')
		f++;
	if(format[i] == flag[f])
		tab->f = flag[f];
	return(format[i] == '%' ? tab->f = '%' : tab->len_flag++);
}

int			ft_printf(const char *format, ...)
{
	va_list		aq;
	t_printf	*tab;
	int			f;

	f = ft_strlen(format);
	va_start(aq, format);
	tab = malloc(sizeof(t_printf));
	tab->start = 0;
	if(find_flag(format, "dfFaAgGeEiboxDuUOXscCpS", tab) == -1)
		ft_putstr(format);
	else
	{
		tab->str = ft_memalloc(tab->start + 1);
		tab->str = ft_strncpy(tab->str, format, tab->start);
		tab->str[tab->start] = '\0';
		tab->len = tab->start;
		while (format[tab->start] != '\0' || tab->start < f)
		{
			tab->ret = NULL;
			if (format[tab->start] == '%')
			{
				tab->i = 0;
				find_flag(format, "dfFaAgGeEiboxDuUOXscCpS", tab);
				if (tab->f == '%')
				{
					free(tab->ret);
					tab->ret = ft_memalloc(1);
					tab->ret[0] = '%';
				}
				else
					g_flag[tab->f](aq, tab);
					tab->str = ft_strjoin(tab->str, tab->ret);
					tab->start += tab->len_flag;
			}
			if (format[tab->start] != '%')
			{
				tab->ret = ft_memalloc(1);
				tab->ret[0] = format[tab->start];
				tab->str = ft_strjoin(tab->str, tab->ret);
				ft_strdel(&tab->ret);
			}
			tab->start++;
		}
	}
	tab->i = ft_strlen(tab->str);
	tab->str[tab->i++] = '\0';
//	printf("str[33] = %c\n", tab->str[33]);
//	printf("flag = %d\n", tab->flag);
//	printf("len_flag = %d\n", tab->len_flag);
//	printf("start = %d\n", tab->start);
//	printf("format[start] = %c\n", format[tab->start - 1]);
//	printf("str = %s", tab->str);
//	printf("ret = %s", tab->ret);
	ft_putstr(tab->str);
	free(tab);
	return (0);
}