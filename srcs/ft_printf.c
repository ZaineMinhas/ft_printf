/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:44:02 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/05 14:50:14 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	int	ft_percent_all(const char *format, va_list args)
{
	if (*format + 1 == 'd' || *format + 1 == 'i')
		return (ft_convert_d_and_i(args));
	if (*format + 1 == 'u')
		return (ft_convert_u(args));
	if (*format + 1 == 'x')
		return (ft_convert_x(args));
	if (*format + 1 == 'X')
		return (ft_convert_xcap(args));
	if (*format + 1 == 'c')
		return (ft_convert_c(args));
	if (*format + 1 == 's')
		return (ft_convert_s(args));
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
