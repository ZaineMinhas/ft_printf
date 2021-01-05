/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:44:02 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/05 19:12:58 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_percent_all(const char *format)
{
	if (*format == 'd' || *format == 'i')
		return (ft_percent_d_and_i(va_arg(list.args, int)));
	else if (*format == 'u')
		return (ft_percent_u(va_arg(list.args, unsigned int)));
	else if (*format == 'x')
		return (ft_percent_x(va_arg(list.args, unsigned int)));
	else if (*format == 'X')
		return (ft_percent_xcap(va_arg(list.args, unsigned int)));
	else if (*format == 'c')
		return (ft_percent_c(va_arg(list.args, int)));
	else if (*format == 's')
		return (ft_percent_s(va_arg(list.args, char *)));
	else if (*format == 'p')
		return (ft_percent_p(va_arg(list.args, void *)));
	else if (*format == '%')
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

int		ft_check_all(const char *format)
{
	ft_flag_checker(format);
}

int		ft_printf(const char *format, ...)
{
	va_list args;

	if (!format)
		return (0);
	ft_reset();
	va_start(list.args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			list.total += ft_check_all(format);
			format++;
		}
		else
		{
			write(1, format, 1);
			list.total++;
		}
		format++;
	}
	va_end(list.args);
	return (list.total);
}
