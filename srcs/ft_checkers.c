/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 18:36:31 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/25 17:33:22 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_get_flag_value(const char **format, int i)
{
	if (g_flag[i] != 3)
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
			g_flag[i] = 1;
		else if (*(*format) == '-')
			g_flag[i] = 2;
		else if (*(*format) == '.')
			g_flag[i] = 4;
		else if (*(*format) == '*' || ft_isdigit((int)*(*format)))
			g_flag[i] = 3;
		if (g_flag[i])
			g_prec[i] = ft_get_flag_value(format, i);
	}
	if (g_flag[0])
		return (1);
	return (0);
}

int	ft_flag_error(const char *format)
{
	if (!(g_percent = ft_ispercent((int)*format)))
		return (1);
	if (g_flag[1] && g_flag[1] != 4)
		return (1);
	if (g_flag[0] && (g_flag[0] == g_flag[1]))
		return (1);
	return (0);
}
