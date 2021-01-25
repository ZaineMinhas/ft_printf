/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:54:26 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/25 17:35:34 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_dot_flag(char *s, int i)
{
	int size;

	size = g_prec[1] < (int)ft_strlen(s) ? g_prec[1] : ft_strlen(s);
	if (g_flag[0] == 1)
		while (i++ < g_prec[0] - size)
			write(1, "0", 1);
	else if (g_flag[0] == 3)
		while (i++ < g_prec[0] - size)
			write(1, " ", 1);
	size = ft_putstr_size(s, g_prec[1]);
	if (g_flag[0] == 2)
		while (i++ < g_prec[0] - size)
			write(1, " ", 1);
	return (size + (i ? --i : i));
}

int			ft_percent_s(char *str)
{
	int size;
	int i;

	i = 0;
	if (!str)
		str = "(null)";
	size = ft_strlen(str);
	if (g_flag[1])
		return (ft_dot_flag(str, i));
	else if (g_flag[0] == 4)
		size = ft_putstr_size(str, g_prec[0]);
	else if (g_flag[0] == 1)
		while (i++ < g_prec[0] - (int)ft_strlen(str))
			write(1, "0", 1);
	else if (g_flag[0] == 3)
		while (i++ < g_prec[0] - (int)ft_strlen(str))
			write(1, " ", 1);
	if (g_flag[0] != 4)
		ft_putstr_fd(str, 1);
	if (g_flag[0] == 2)
		while (i++ < g_prec[0] - (int)ft_strlen(str))
			write(1, " ", 1);
	return (size + (i ? --i : i));
}
