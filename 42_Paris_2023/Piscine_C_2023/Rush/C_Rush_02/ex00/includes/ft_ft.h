/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 15:04:32 by ketrevis          #+#    #+#             */
/*   Updated: 2023/08/20 18:46:21 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FT_H
# define FT_FT_H

int	    ft_strlen(char *str);
int	    ft_atoi(char *str);
int	    nb_len_line(char *line);
int	    found_key_char(char c, char *dict);
int	    found_key(char *nb, char *dict);
int     is_number(char c);
int	    is_not_printable(char c);

char    **split_file(char *path);
void	ft_putstr(char *str);
void	print_line_value(char *str);
void	ft_putchar(char c);
void	parse_file(char *nb, char **dict);

#endif