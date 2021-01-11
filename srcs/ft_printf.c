/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:44:02 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/11 15:17:21 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_percent_all(const char *format)
{
	if (*format == 'd' || *format == 'i')
		return (ft_percent_d_and_i(va_arg(var.args, int)));
	else if (*format == 'u')
		return (ft_percent_u(va_arg(var.args, unsigned int)));
	else if (*format == 'x')
		return (ft_percent_x(va_arg(var.args, unsigned int)));
	else if (*format == 'X')
		return (ft_percent_xcap(va_arg(var.args, unsigned int)));
	else if (*format == 'c')
		return (ft_percent_c(va_arg(var.args, int)));
	else if (*format == 's')
		return (ft_percent_s(va_arg(var.args, char *)));
	else if (*format == 'p')
		return (ft_percent_p(va_arg(var.args, void *)));
	else if (*format == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	return (0);
}

void	ft_reset(void)
{
	var.total = 0;
	var.error = 0;
	var.new_format = 0;
	var.flag[0] = 0;
	var.flag[1] = 0;
	var.prec[0] = 0;
	var.prec[1] = 0;
	var.percent = 0;
}

int		ft_check_all(const char *format)
{
	if (ft_flag_checker(format))
		ft_flag_value(format);
}

int		ft_printf(const char *format, ...)
{
	va_list args;

	if (!format)
		return (0);
	ft_reset();
	va_start(var.args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			var.total += ft_check_all(format);
			format++;
		}
		else
		{
			write(1, format, 1);
			var.total++;
		}
		format++;
	}
	va_end(var.args);
	return (var.total);
}
