/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 18:36:31 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/19 16:43:03 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_get_flag_value(const char **format, int i)
{
	if (var.flag[i] != 3)
		(*format)++;
	return (ft_atoi_remix(format));
}

int	ft_flag_checker(const char **format)
{
	int i;

	i = -1;
	while (++i < 2)
	{
		if (*(*format) == '0')
			var.flag[i] = 1;
		else if (*(*format) == '-')
			var.flag[i] = 2;
		else if (*(*format) == '.')
			var.flag[i] = 4;
		else if (*(*format) == '*' || ft_isdigit((int)*(*format)))
			var.flag[i] = 3;
		if (var.flag[i])
			var.prec[i] = ft_get_flag_value(format, i);
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
	return (0);
}
