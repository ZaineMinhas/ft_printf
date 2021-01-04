/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:44:02 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/04 14:23:03 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_percent_all(const char *format, va_list args)
{
	if (*format == 'd' || *format == 'i')
		return (ft_percent_d_and_i(va_arg(args, int)));
	if (*format == 'u')
		return (ft_percent_u(va_arg(args, unsigned int)));
	if (*format == 'x')
		return (ft_percent_x(va_arg(args, unsigned int)));
	if (*format == 'X')
		return (ft_percent_xcap(va_arg(args, unsigned int)));
	if (*format == 'c')
		return (ft_percent_c(va_arg(args, int)));
	if (*format == 's')
		return (ft_percent_s(va_arg(args, char *)));
	if (*format == 'p')
		return (ft_percent_p(va_arg(args, void *)));
	if (*format == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

void	ft_reset(void)
{
	list.total = 0;
	list.the_flag[0] = 0;
	list.the_flag[1] = 0;
	list.prec[0] = 0;
	list.prec[1] = 0;
}

int		ft_flag_checker(const char *format, va_list args)
{
	if (*format == '-')
		list.the_flag[0] = 1;
	else if (*format == '0')
		list.the_flag[0] = 2;
	else if (*format == '*')
		list.the_flag[0] = 3;
	else if (*format == '.')
		list.the_flag[0] = 4;
	else if (ft_isdigit((int)*format))
		list.the_flag[0] = 5;
	if (list.the_flag[0])
		format++;
	if (*format == '.' && list.the_flag[0] != 3)
		list.the_flag[1] = 1;
}

int		ft_printf(const char *format, ...)
{
	va_list args;

	if (!format)
		return (0);
	ft_reset();
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			list.total += ft_flag_checker(format, args);
			format++;
		}
		else
		{
			write(1, format, 1);
			list.total++;
		}
		format++;
	}
	va_end(args);
	return (list.total);
}
