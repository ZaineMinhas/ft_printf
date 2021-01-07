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
int	ft_ispercent(const char *format, int index)
{
	if (format[index] == 'c' || format[index] == 'd' ||\
	format[index] == 'i' || format[index] == 'p' || format[index] == 's' ||\
	format[index] == 'u' || format[index] == 'x' || format[index] == 'X')
		return (1);
	return (0);
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


int	ft_get_flag_value(const char **format)
{
	int	res;

	res = 0;
	if (**format == '*')
	{
		(*format)++;
		return (va_arg(args, int));
	}
	else if (ft_isdigit((int)**format))
	{
		res = ft_atoi(*format);
		while (ft_isdigit((int)**format))
			(*format)++;
		return (res);
	}
	return (res);
}

int	ft_flag_checker(const char *format)
{
	int i;

	i = -1;
	while (++i < 2)
	{
		if (*format == '0')
			the_flag[i] = 1;
		else if (*format == '-')
			the_flag[i] = 2;
		else if (*format == '.')
			the_flag[i] = 4;
		else if (*format == '*' || ft_isdigit((int)*format))
			the_flag[i] = 3;
		if (the_flag[i])
		{
			format++;
			if (the_flag[i] == 1 || the_flag[i] == 2)
			{
				while (*format == *(format - 1))
					format++;
			}
			// if (the_flag[i] == 4)
			// 	format++;
			prec[i] = ft_get_flag_value(&format);
		}
	}
	if (!the_flag[0])
		return (0);
	return (1);
}


int		ft_test(char *format, ...)
{
	va_start(args, format);
	if (ft_flag_checker(format))
	{
		printf("VICTORY !!!\n");
		printf("\n--- LES FLAGS ---\n");
		printf("%d\n", the_flag[0]);
		printf("%d\n", the_flag[1]);
		printf("\n--- LES PRECISIONS ---\n");
		printf("%d\n", prec[0]);
		printf("%d\n", prec[1]);
	}
	else
		printf("ERROR\n");
	va_end(args);
	return (0);
}
int	main(void)
{
	char format[100] = "------------0000045";
	ft_test(format, 45, 66);
	return (0);
}

// la commande : c le_ziiz.c && clear && ./a.out 