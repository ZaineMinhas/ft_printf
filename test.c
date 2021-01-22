#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	char *str = "salut";
	char **ptr;

	ptr = &str;
	printf("\nle faux : %d\n", ft_printf("|%30.23p|\n", ptr));
	printf("\nle vrai : %d\n", printf("|%30.23p|\n", ptr));
	return (0);
}

//la commande : clear && gcc test.c libftprintf.a && clear && ./a.out | cat -e