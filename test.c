#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include "ft_printf.h"

int	main(void)
{
	char *str = "0-23";
	char **ptr;

	ptr = &str;
	printf("\nle faux : %d\n", ft_printf("%% *.5i 42 == |%*.5i|", 4, 42));
	printf("\nle vrai : %d\n", printf("%% *.5i 42 == |%*.5i|", 4, 42));
	return (0);
}

//la commande : clear && gcc test.c libftprintf.a && clear && ./a.out | cat -e