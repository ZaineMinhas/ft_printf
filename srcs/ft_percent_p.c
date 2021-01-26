/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:13:09 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/26 19:36:27 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	int		ft_percent_x_remix(unsigned long n)
{
	char	*base;
	char	*res;
	int		power;
	int		i;

	base = "0123456789abcdef";
	power = ft_hexlen_ul(n);
	if (!(res = ft_calloc(sizeof(char), (power + 1))))
		return (0);
	i = ft_hexlen_ul(n);
	while (power--)
	{
		res[power] = base[n % 16];
		n /= 16;
	}
	ft_putstr_fd(res, 1);
	free((void *)res);
	return (i);
}

static int		ft_dot_flag(int i, unsigned long adrs)
{
	int				size;
	int				j;

	j = 0;
	size = g_prec[1] < ft_hexlen_ul(adrs) ? ft_hexlen_ul(adrs) : g_prec[1];
	!(!adrs && !g_prec[1]) ? write(1, "", 0) : size--;
	if (g_flag[0] == 1 || g_flag[0] == 3)
		while (i++ < g_prec[0] - size - 2)
			write(1, " ", 1);
	ft_putstr_fd("0x", 1);
	while (j++ < g_prec[1] - ft_hexlen_ul(adrs))
		write(1, "0", 1);
	!(!adrs && !g_prec[1]) ? ft_percent_x_remix(adrs) : write(1, "", 0);
	if (g_flag[0] == 2)
		while (i++ < g_prec[0] - size - 2)
			write(1, " ", 1);
	return (size + 2 + (i ? --i : i));
}

int				ft_percent_p(void *ptr)
{
	unsigned long	adrs;
	int				size;
	int				i;

	i = 0;
	adrs = (unsigned long)ptr;
	if (g_flag[1])
		return (ft_dot_flag(i, adrs));
	size = ft_hexlen_ul(adrs);
	if (g_flag[0] == 3)
		while (i++ < g_prec[0] - size - 2)
			write(1, " ", 1);
	ft_putstr_fd("0x", 1);
	if (g_flag[0] == 1)
		while (i++ < g_prec[0] - size - 2)
			write(1, "0", 1);
	else if (g_flag[0] == 4)
		while (i++ < g_prec[0] - size)
			write(1, "0", 1);
	!(!adrs && g_flag[0] == 4 && !g_prec[0]) ?
	ft_percent_x_remix(adrs) : size--;
	if (g_flag[0] == 2)
		while (i++ < g_prec[0] - size - 2)
			write(1, " ", 1);
	return (size + 2 + (i ? --i : i));
}
