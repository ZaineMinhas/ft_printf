/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 18:36:31 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/06 18:50:58 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_flag_checker(const char *format)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (++j < 2)
	{
		if (format[i] == '0')
			list.the_flag[j] = 1;
		else if (format[i] == '-')
		{
			list.the_flag[j] = 2;
			while (format[i] == '-')
				i++;
		}
		else if (format[i] == '*' || ft_isdigit((int)format[i]))
			list.the_flag[j] = 3;
		else if (format[i] == '.')
			list.the_flag[j] = 4;
	}
}

int	ft_flag_value(const char *format)
{
	int i;

	i = 0;
	while (list.the_flag[i] && i < 2)
	{
		if (*format == '*')
		{
			list.prec[i] = va_arg(list.args, int);
			format++;
		}
		else
		{
			format++;
			list.prec[i] = ft_atoi(format);
			while (ft_isdigit((int)*format))
				format++;
		}
		i++;
	}
	return (0);
}