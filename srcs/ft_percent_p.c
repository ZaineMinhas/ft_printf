/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:13:09 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/25 17:43:56 by zminhas          ###   ########.fr       */
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

static int		ft_dot_flag(void *ptr, int i)
{
	unsigned long	adrs;
	int				size;
	int				j;

	j = 0;
	adrs = (unsigned long)ptr;
	size = g_prec[1] < ft_hexlen_ul(adrs) ? ft_hexlen_ul(adrs) : g_prec[1];
	if (g_flag[0] == 1 || g_flag[0] == 3)
		while (i++ < g_prec[0] - size - 2)
			write(1, " ", 1);
	ft_putstr_fd("0x", 1);
	while (j++ < g_prec[1] - ft_hexlen_ul(adrs))
		write(1, "0", 1);
	ft_percent_x_remix(adrs);
	if (g_flag[0] == 2)
		while (i++ < g_prec[0] - size - 2)
			write(1, " ", 1);
	return (ft_hexlen_ul(adrs) + 2 + (--j) + (i ? --i : i));
}

int				ft_percent_p(void *ptr)
{
	unsigned long	adrs;
	int				i;

	i = 0;
	if (g_flag[1])
		return (ft_dot_flag(ptr, i));
	adrs = (unsigned long)ptr;
	if (g_flag[0] == 3)
		while (i++ < g_prec[0] - ft_hexlen_ul(adrs) - 2)
			write(1, " ", 1);
	ft_putstr_fd("0x", 1);
	if (g_flag[0] == 1 || g_flag[0] == 4)
		while (i++ < g_prec[0] - ft_hexlen_ul(adrs) - 2)
			write(1, "0", 1);
	ft_percent_x_remix(adrs);
	if (g_flag[0] == 2)
		while (i++ < g_prec[0] - ft_hexlen_ul(adrs) - 2)
			write(1, " ", 1);
	return (ft_hexlen_ul(adrs) + 2 + (i ? --i : i));
}
