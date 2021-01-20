#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("\nle faux : %d\n", ft_printf("salut %s", NULL));
	printf("\nle vrai : %d\n", printf("salut %s", NULL));
	return (0);
}
