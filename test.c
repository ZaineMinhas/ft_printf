#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	char *lol;

	lol = ft_calloc(sizeof(char), 1000);
	printf("%p\n", lol);
	ft_printf("%p\n", lol);
	return (0);
}