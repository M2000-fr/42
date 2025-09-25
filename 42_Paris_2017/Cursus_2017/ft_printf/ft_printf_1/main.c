
#include "ft_printf.h"
#include <stdio.h>
#include <float.h> 
#include <math.h>
#include <locale.h>

int		main(void)
{
	double			i;
	unsigned int	nb;
	void			*hex;
	wchar_t			*sh;
	setlocale(LC_ALL, "");

	i = -0.000001;
	hex = malloc(sizeof(void) * 19);
	sh = malloc(sizeof(wchar_t) * 4);
	nb = 19;
	sh[0] = 0x10FFFF;
	sh[1] = 0x10FFFF;
	sh[2] = 0x10FFFF;
	sh[3] = 0;
	ft_printf("<--------------------------------Mon Printf-------------------------------->\n");
	ft_printf("Bonjour c'est le premier test sans arguments\n");
	ft_printf("C'est le premier test avec%s\n", " une chaine de caractere !");
	ft_printf("C'est le deuxieme test avec%s et la%s\n", " une chaine de caractere", " une deuxieme chaine !");
	ft_printf("C'est le premier test avec %c caractere !\n", '1');
	ft_printf("C'est le deuxieme test avec %c caractere et une%s!\n", 'a', " chaine de caractere");
	ft_printf("C'est le premier test avec %d !\n", 546000);
	ft_printf("C'est le deuxieme test avec %d !\n", -2147483648);
	ft_printf("C'est le premier test avec un double : %e !\n",  -i * 9.999999e+307);
	ft_printf("C'est le deuxieme test avec un double : %e !\n", i - 5011995);
	ft_printf("C'est le troisieme test avec un double : %E !\n", i * -9.999999e+307);
	ft_printf("C'est le quatrieme test avec un double : %E !\n", i / 1.235958e+36);
	// ft_printf("C'est le premier test avec un double : %f !\n",  9.999999e+05);
	// i = 5011995;
	// ft_printf("C'est le deuxieme test avec un double : %f !\n", 5011995);
	// ft_printf("C'est le troisieme test avec un double : %f !\n", -9.999999e+307);
	// ft_printf("C'est le quatrieme test avec un double : %f !\n", 1.235958e+36);
	ft_printf("C'est le premier test avec une convertion en octal : 29 -> %o\n", 29);
	ft_printf("C'est le premier test avec un chiffre decimal : 10 -> %u\n", 10);
	ft_printf("C'est le premier test avec une convertion en hexa : 10 -> %x\n", 10);
	ft_printf("C'est le deusieme test avec un Octal : 100 -> %O\n", 999);
	ft_printf("C'est le deusieme test avec un Chiffre decimal : 101 -> %U\n", 101);
	ft_printf("C'est le deusieme test avec une convertion en Hexa : 16 -> %X\n", 75);
	ft_printf("C'est le premier test avec un wchar_t = %C\n", 0x10FFFF);
	ft_printf("C'est le deuxieme test avec une chaine de wchar_t = %S\n", sh);
	ft_printf("C'est le premier test pour afficher l adresse dun ponteur = %p\n", hex);
	ft_printf("ft_prcent = %%\n");
	ft_printf("<-------------------------------Le vrai printf----------------------------->\n");
	printf("void\n");
	printf("ft_s = %s\n", "first");
	printf("ft_s & ft_c = %s %c\n", "fisrt", 'c');
	printf("ft_c = %c\n", 'c');
	printf("ft_d = %d\n", -15464);
	printf("ft_e = %e\n", -i * 9.999999e+307);
	printf("ft_E = %E\n", i / 1.235958e+36);
	printf("ft_o = %o\n", 29);
	printf("ft_u = %u\n", 10);
	printf("ft_x = %x\n", 10);
	printf("ft_O = %O\n", 999);
	printf("ft_U = %U\n", 101);
	printf("ft_X = %X\n", 75);
	printf("ft_C = %C\n", 0x10FFFF);
	printf("ft_S = %S\n", sh);
	printf("ft_p = %p\n", hex);
	printf("ft_prcent = %%\n");
	return (0);
}