#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("\nle faux : %d\n", ft_printf("salut %-12.1d", 123));
	printf("\nle vrai : %d\n", printf("salut %-12.1d", 123));
	return (0);
}
