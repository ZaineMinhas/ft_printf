/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:44:02 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/02 15:27:17 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*int		ft_printf(const char *format, ...)
{
	int		i;

	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			if (*format + 1 == 'd' || *format + 1 == 'i')
				i += ft_convert_d_and_i();
			if (*format + 1 == 'u')
				i += ft_convert_u();
//			if (*format + 1 == 'x' || *format + 1 == 'X')

			if (*format + 1 == 'c')
				i += ft_convert_c();
			if (*format + 1 == 's')
				i += ft_convert_s();
//			if (*format + 1 == 'p')

			if (*format + 1 == '%')
			{
				write(1, "%", 1);
				i++;
			}
		}
		else
		{
			ft_putchar_fd(*format, 1);
			i++;
		}
		*format++;
	}
	return (i);
}*/
