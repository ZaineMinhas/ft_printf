/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 18:36:31 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/07 19:41:52 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_get_flag_value(const char **format)
{
	int	res;

	res = 0;
	if (**format == '*')
	{
		(*format)++;
		return (va_arg(list.args, int));
	}
	else if (ft_isdigit((int)**format))
	{
		res = ft_atoi(*format);
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
			list.the_flag[i] = 1;
		else if (*format == '-')
			list.the_flag[i] = 2;
		else if (*format == '.')
			list.the_flag[i] = 4;
		else if (*format == '*' || ft_isdigit((int)*format))
			list.the_flag[i] = 3;
		if (list.the_flag[i])
		{
			format++;
			if (list.the_flag[i] == 1 || list.the_flag[i] == 2)
				while (*format == *(format - 1))
					format++;
			list.prec[i] = ft_get_flag_value(&format);
		}
	}
	if (!list.the_flag[0])
		return (0);
	return (1);
}
