/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:44:02 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/22 13:29:48 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_percent_all(int percent)
{
	if (percent == 2)
		return (ft_percent_d_and_i(va_arg(var.args, int)));
	else if (percent == 5)
		return (ft_percent_u(va_arg(var.args, unsigned int)));
	else if (percent == 6)
		return (ft_percent_x(va_arg(var.args, unsigned int), "0123456789abcdef"));
	else if (percent == 7)
		return (ft_percent_x(va_arg(var.args, unsigned int), "0123456789ABCDEF"));
	else if (percent == 1)
		return (ft_percent_c(va_arg(var.args, int)));
	else if (percent == 4)
		return (ft_percent_s(va_arg(var.args, char *)));
	else if (percent == 3)
		return (ft_percent_p(va_arg(var.args, void *)));
	else if (percent == 8)
		return(ft_percent_c('%'));
	return (0);
}

void	ft_reset(void)
{
	var.total = 0;
	var.flag[0] = 0;
	var.flag[1] = 0;
	var.prec[0] = 0;
	var.prec[1] = 0;
	var.percent = 0;
}

int		ft_check_all(const char **format)
{
	if (ft_flag_checker(format))
		ft_ajust_var();
	if (ft_flag_error(*format))
		return (-1);
	ft_second_ajust();
	format += 2;
	return (ft_percent_all(var.percent));
}

int		ft_printf(const char *format, ...)
{
	if (!format)
		return (0);
	ft_reset();
	va_start(var.args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			var.total += ft_check_all(&format);
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
