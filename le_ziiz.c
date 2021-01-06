#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int the_flag[2];
int prec[2];
va_list args;

void	ft_reset(void)
{
	the_flag[0] = 0;
	the_flag[1] = 1;
	prec[0] = 0;
	prec[1] = 0;
}

int		ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}

int		ft_atoi(const char *str)
{
	unsigned long long		nb;
	unsigned long long		nb_tmp;
	int						pos_neg;
	int						i;

	i = 0;
	pos_neg = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			pos_neg = -1;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		nb_tmp = nb;
		nb = nb * 10 + (str[i++] - 48);
		if (nb < nb_tmp || nb > LLONG_MAX)
			return ((pos_neg == 1) ? -1 : 0);
	}
	return ((int)nb * pos_neg);
}

int	ft_pass(const char *format, int index)
{
	int i;

	i = 0;
	if (format[index] == '*')
		return (1);
	else
	{
		while (ft_isdigit((int)format[index]))
		{
			index++;
			i++;
		}
		return (index - i);
	}
	
}

int	ft_flag_checker(const char *format)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (++j < 2)
	{
		if (format[i] == '0')
			the_flag[j] = 1;
		else if (format[i] == '-')
		{
			the_flag[j] = 2;
			while (format[i] == '-')
				i++;
		}
		else if (format[i] == '*' || ft_isdigit((int)format[i]))
			the_flag[j] = 3;
		else if (format[i] == '.')
			the_flag[j] = 4;
		if (the_flag[0])
			i += ft_pass(format, i);
	}
	printf("%d\n", the_flag[0]);
	printf("%d\n", the_flag[1]);
	return (1);
}

int	ft_flag_value(const char *format)
{
	int i;

	i = 0;
	if (the_flag[i] && i < 2)
	{
		if (*format == '*')
		{
			prec[i] = va_arg(args, int);
			format++;
		}
		else
		{
			format++;
			prec[i] = ft_atoi(format);
			while (ft_isdigit((int)*format))
				format++;
		}
		i++;
	}
	printf("%d\n", prec[0]);
	printf("%d\n", prec[1]);
	return (0);
}

int		ft_test(char *format, ...)
{
	va_start(args, format);
	if (ft_flag_checker(format))
		ft_flag_value(format);
	else
		printf("ERROR\n");
	va_end(args);
	return (0);
}
int	main(void)
{
	char format[100] = "----------22.45";
	ft_test(format, 10);
	return (0);
}