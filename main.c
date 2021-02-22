#include <stdio.h>
#include "ft_printf.h"

int	main()
{
	printf(" le vrai : %d\n", printf(" 0*%0-*.*d ", 6, 2, 102));
	printf(" le faux : %d\n", ft_printf(" 0*%0-*.*d ", 6, 2, 102));
}