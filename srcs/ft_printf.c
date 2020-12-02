/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:44:02 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/02 18:25:58 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	int	ft_percent_all(const char *format)
{
	if (*format + 1 == 'd' || *format + 1 == 'i')
		return (ft_convert_d_and_i());
	if (*format + 1 == 'u')
		return (ft_convert_u());
	if (*format + 1 == 'x')
		return (ft_convert_x());
	if (*format + 1 == 'X')
		return (ft_convert_xcap());
	if (*format + 1 == 'c')
		return (ft_convert_c());
	if (*format + 1 == 's')
		return (ft_convert_s());
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

	i = 0;
	while (*format)
	{
		if (*format == '%')
			i += ft_percent_all(format);
		else
		{
			ft_putchar_fd(*format, 1);
			i++;
		}
	*format++;
	}
	return (i);
}
