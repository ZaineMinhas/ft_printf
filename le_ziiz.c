#include <stdio.h>

int		ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int		ft_flag_checker(const char *format)
{
	int i;
	int the_flag[2];


	i = 0;
	the_flag[0] = 0;
	the_flag[1] = 0;
	if (format[i] == '0')
		the_flag[0] = 1;
	else if (format[i] == '-')
		the_flag[0] = 2;
	else if (format[i] == '*' || ft_isdigit((int)format[i]))
		the_flag[0] = 3;
	else if (format[i] == '.')
		the_flag[0] = 4;
	if (the_flag[0])
		i++;
	while (ft_isdigit((int)format[i]) || (format[i] == '*' && format[i + 1] != '*'))
		i++;
	if (format[i] == '.' && the_flag[0] != 4)
		the_flag[1] = 4;
	printf("%d\n", the_flag[0]);
	printf("%*d\n", the_flag[1]);
	return (0);
}

int	main(void)
{
	ft_flag_checker("-484456.45564");
	return 0;
}