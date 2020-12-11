/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:44:02 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/11 13:51:39 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	int	ft_percent_all(const char *format, va_list args)
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

// static	int	ft_flagchecker(const char *format, va_list args)
// {
// 	int nb;

// 	if (*format == 'c' || *format == 'd' || *format == 'i' || *format == 'p' ||\
// 	 *format == 's' || *format == 'u' ||	*format == 'x' || *format == 'X')
// 		return (ft_percent_all(format, args));
// 	nb = 0;
// 	if (ft_isdigit(*format))
// 	{
// 		while (ft_isdigit(*format))
// 		{
// 			nb++;
// 			format++;
// 		}
// 		nb = ft_atoi(ft_substr((format - nb), 0, nb));
// 	}
// 	else if (*format == '*')
// 	{
// 		nb = va_arg(args, int);
// 		format++;
// 	}
// 	if (*format == '-')
// 		return (ft_flag_minus(format, va_arg(args, int)));
// 	if (*format == '0' || *format == '.')
// 		return (ft_flag_zero_and_point(format, va_arg(args, int)));
// 	if (*format == '*')
// 		return (ft_flag_star(format, va_arg(args, int)));
// 	return (ft_percent_all(format, args));
// }

int			ft_printf(const char *format, ...)
{
	int		i;
	va_list args;

	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
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
