/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 18:36:31 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/08 14:53:25 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_get_flag_value(const char **format, int index)
{
	int	res;

	res = 0;
	if (var.the_flag[index] != 3)
		(*format)++;
	if (**format == '*')
	{
		(*format)++;
		return (va_arg(var.args, int));
	}
	else if (ft_isdigit((int)**format))
	{
		res = ft_atoi_remix(*format);
		while (ft_isdigit((int)**format))
			(*format)++;
		return (res);
	}
	return (res);
}

int	ft_flag_checker(const char *format)
{
	int i;

	i = -1;
	while (++i < 2)
	{
		if (*format == '0')
			var.the_flag[i] = 1;
		else if (*format == '-')
			var.the_flag[i] = 2;
		else if (*format == '.')
			var.the_flag[i] = 4;
		else if (*format == '*' || ft_isdigit((int)*format))
			var.the_flag[i] = 3;
		if (var.the_flag[i])
		{
			if (var.the_flag[i] == 1 || var.the_flag[i] == 2)
				while (*format == *(format - 1))
					format++;
			var.prec[i] = ft_get_flag_value(&format, i);
		}
	}
	if (var.the_flag[0])
		return (1);
	return (0);
}
