#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	printf("\nle faux : %d\n", ft_printf("|%*s|\n", 250, "hello"));
	printf("\nle vrai : %d\n", printf("|%*s|\n", 250, "hello"));
	return (0);
}

//la commande : clear && gcc test.c libftprintf.a && clear && ./a.out | cat -e