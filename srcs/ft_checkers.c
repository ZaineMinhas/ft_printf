/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 18:36:31 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/12 18:30:10 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_get_flag_value(const char *format, int *i, int j)
{
	if (var.flag[j] != 3)
		(*i)++;
	return (ft_atoi_remix(*format, i));
}

int	ft_flag_checker(const char *format)
{
	int i;
	int j;

	i = 0;
	j = -1;
	while (++j < 2)
	{
		if (format[i] == '0')
			var.flag[j] = 1;
		else if (format[i] == '-')
			var.flag[j] = 2;
		else if (format[i] == '.')
			var.flag[j] = 4;
		else if (format[i] == '*' || ft_isdigit((int)format[i]))
			var.flag[j] = 3;
		if (var.flag[j])
			var.prec[j] = ft_get_flag_value(format, &i, j);
	}
	if (var.flag[0])
		return (1);
	return (0);
}

int	ft_flag_error(const char *format)
{
	if (!(var.percent = ft_ispercent((int)*format)))
		return (1);
	if (var.flag[1] && var.flag[1] != 4)
		return (1);
	if (var.flag[0] && (var.flag[0] == var.flag[1]))
		return (1);
	if (var.prec[0] < 0 || var.prec[1] < 0)
		return (1);
	// a suivre. . .
	return (0);
}
