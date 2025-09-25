/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 03:46:55 by maechard          #+#    #+#             */
/*   Updated: 2017/11/27 03:46:57 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		main(void)
{
 	char	*str;
 	char	*str1;

 	str = "monde";
	str1 = "vous";
	ft_printf("a%c\n", 'b');
	ft_printf("%c %c\n", 'a', 98);
	ft_printf("%c%c%c%c%c%c\n", 'a', 98, 99, 'd', 'e', 102);
	ft_printf("Bonjour\n");
	ft_printf("%s\n", "Bonjour moi");
	ft_printf("Bonjour %s\n", "maxime");
	ft_printf("BonTRESGROSCHIBREjour %s %s %s\n", "tout", "le", "monde");
	ft_printf("BonjGROSSE MEBHEISF UISGHRUO8E87654JOREINORGD-04E96244525WQour %s le %s %s %s%s\n", "tout", str, str1, "etes", " teuber");
	ft_printf("Bonjour %s %d etudiants\n", "les", 900);
	ft_printf("%d %d %d \n", 987, 654, 321);
	ft_printf("len str = %d\n", ft_strlen(str));
	ft_printf("%o\n", 98);
	ft_printf("o = %o o = %o\n", 98, 105);
	ft_printf("%o%o%o\n", 98, 201, 683);
	ft_printf("%x\n", 98);
	ft_printf("x = %x x = %x\n", 98, 105);
	ft_printf("%X%X%X\n", 98, 201, 683);
	ft_printf("%f\n", 10.32456);
	ft_printf("%f\n", -106515165461.32456);
	ft_printf("pi = %f et des nombres randoms %f%f\n voila\n", 3.14159265359, -0.42, -42.42 + 23);
	ft_printf("%.9f\n", -10.32456);
	ft_printf("%.20f\n", -10.32596);
 }