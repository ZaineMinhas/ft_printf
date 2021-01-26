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
	char	**v = &o;

	printf("\nle faux : %d\n", ft_printf("%2.9p", NULL));
	printf("\nle vrai : %d\n", printf("%2.9p", NULL));
	return (0);
}

//la commande : clear && gcc test.c libftprintf.a && clear && ./a.out | cat -e
//la commande boosté : make && clear && gcc test.c libftprintf.a && clear && ./a.out | cat -e && rm a.out