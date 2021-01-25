/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:20:37 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/25 17:36:23 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_dot_flag(int n, int i)
{
	int size;
	int j;

	j = 0;
	size = g_prec[1] < ft_intlen_ui(n) ? ft_intlen_ui(n) : g_prec[1];
	!(!n && g_prec[1] == 0) ? write(1, "", 0) : i--;
	if ((g_flag[0] == 1 || g_flag[0] == 3))
		while (i++ < g_prec[0] - size)
			write(1, " ", 1);
	while (j++ < g_prec[1] - ft_intlen_ui(n))
		write(1, "0", 1);
	!(!n && g_prec[1] == 0) ? ft_putnbr_ui(n) : write(1, "", 0);
	if (g_flag[0] == 2)
		while (i++ < g_prec[0] - size)
			write(1, " ", 1);
	g_prec[0] == 0 && g_prec[1] == 0 ? i-- : write(1, "", 0);
	return (ft_intlen_ui(UINT_MAX + n + 1) + (i > 0 ? --i : i) + (--j));
}

int				ft_percent_u(int n)
{
	int size;
	int i;

	i = 0;
	if (g_flag[1])
		return (ft_dot_flag(n, i));
	size = ft_intlen_ui(UINT_MAX + n + 1);
	if (g_flag[0] == 1 || g_flag[0] == 4)
		while (i++ < g_prec[0] - ft_intlen_ui(n))
			write(1, "0", 1);
	else if (g_flag[0] == 3)
		while (i++ < g_prec[0] - ft_intlen_ui(n))
			write(1, " ", 1);
	!(!n && g_flag[0] == 4 && g_prec[0] == 0) ? ft_putnbr_ui(n) : size--;
	if (g_flag[0] == 2)
		while (i++ < g_prec[0] - ft_intlen_ui(n))
			write(1, " ", 1);
	return (size + (i ? --i : i));
}
