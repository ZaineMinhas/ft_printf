#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	printf("\nle faux : %d\n", ft_printf("|%-3.56%|\n"));
	printf("\nle vrai : %d\n", printf("|%-3.56%|\n"));
	return (0);
}

//la commande : clear && gcc test.c libftprintf.a && clear && ./a.out | cat -e