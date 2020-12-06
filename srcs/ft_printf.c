/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:44:02 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/06 16:38:31 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	int	ft_percent_all(const char *format, va_list args)
{
	format++;
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

int		ft_printf(const char *format, ...)
{
	int		i;
	va_list args;

	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			i += ft_percent_all(format, args);
			format++;
		}
		else
		{
			write(1, format, 1);
			i++;
		}
	format++;
	}
	va_end(args);
	return (i);
}
