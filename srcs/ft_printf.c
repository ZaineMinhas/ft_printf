/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:44:02 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/26 17:11:41 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_percent_all(int percent)
{
	if (percent == 2)
		return (ft_percent_d_and_i(va_arg(g_args, int)));
	else if (percent == 5)
		return (ft_percent_u(va_arg(g_args, unsigned int)));
	else if (percent == 6)
		return (ft_percent_x(va_arg(g_args, unsigned int),
		"0123456789abcdef"));
	else if (percent == 7)
		return (ft_percent_x(va_arg(g_args, unsigned int),
		"0123456789ABCDEF"));
	else if (percent == 1)
		return (ft_percent_c(va_arg(g_args, int)));
	else if (percent == 4)
		return (ft_percent_s(va_arg(g_args, char *)));
	else if (percent == 3)
		return (ft_percent_p(va_arg(g_args, void *)));
	else if (percent == 8)
		return (ft_percent_percent());
	return (0);
}

void	ft_reset(void)
{
	g_flag[0] = 0;
	g_flag[1] = 0;
	g_prec[0] = 0;
	g_prec[1] = 0;
	g_percent = 0;
}

int		ft_check_all(const char **format)
{
	if (ft_flag_checker(format))
		ft_ajust_var();
	if (ft_flag_error(*format))
		return (-1);
	ft_second_ajust();
	return (ft_percent_all(g_percent));
}

int		ft_printf(const char *format, ...)
{
	int total;

	if (!format)
		return (0);
	total = 0;
	va_start(g_args, format);
	while (*format)
	{
		ft_reset();
		if (*format == '%')
		{
			format++;
			total += ft_check_all(&format);
		}
		else
		{
			write(1, format, 1);
			total++;
		}
		format++;
	}
	va_end(g_args);
	return (total);
}
