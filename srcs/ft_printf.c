/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:44:02 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/05 15:17:41 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	int	ft_percent_all(const char *format, va_list args)
{
	if (*format + 1 == 'd' || *format + 1 == 'i')
		return (ft_percent_d_and_i(va_arg(args, int)));
	if (*format + 1 == 'u')
		return (ft_percent_u(va_arg(args, unsigned int)));
	if (*format + 1 == 'x')
		return (ft_percent_x(va_arg(args, unsigned int)));
	if (*format + 1 == 'X')
		return (ft_percent_xcap(va_arg(args, unsigned int)));
	if (*format + 1 == 'c')
		return (ft_percent_c(va_arg(args, int)));
	if (*format + 1 == 's')
		return (ft_percent_s(va_arg(args, char *)));
	if (*format + 1 == 'p')

	if (*format + 1 == '%')
	{
		write(1, "%", 1);
		return (1);
	}
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
			i += ft_percent_all(format, args);
		else
		{
			ft_putchar_fd(*format, 1);
			i++;
		}
	*format++;
	}
	va_end(args);
	return (i);
}
