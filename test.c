#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	//printf("\nle faux : %d\n", ft_printf("%-1d", d));
	//printf("\nle vrai : %d\n", printf("%-1d", d));
	//printf(" --- Return : %d\n", printf("\n%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d, %-1d, %-1d", i, j, k, l, m, c, e, d)); //T28
	//printf(" --- Return : %d\n", ft_printf("\n%-1.i, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d, %-1.d, %-1d", i, j, k, l, m, c, e, d)); //T28
	return (0);
}

//la commande : clear && gcc test.c libftprintf.a && clear && ./a.out | cat -e