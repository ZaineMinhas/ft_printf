/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:13:09 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/22 20:14:25 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	int		ft_uhexlen(unsigned long n)
{
	int len;

	len = 0;
	while (n /= 16)
		len++;
	return (++len);
}

static	int		ft_percent_x_remix(unsigned long n)
{
	char	*base;
	char	*res;
	int		power;
	int		i;

	base = "0123456789abcdef";
	power = ft_uhexlen(n);
	if (!(res = ft_calloc(sizeof(char), (power + 1))))
		return (0);
	i = ft_uhexlen(n);
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
	size = var.prec[1] < ft_uhexlen(adrs) ? ft_uhexlen(adrs) : var.prec[1];
	if (var.flag[0] == 1 || var.flag[0] == 3)
		while (i++ < var.prec[0] - size - 2)
			write(1, " ", 1);
	ft_putstr_fd("0x", 1);
	while (j++ < var.prec[1] - ft_uhexlen(adrs))
		write(1, "0", 1);
	ft_percent_x_remix(adrs);
	if (var.flag[0] == 2)
		while (i++ < var.prec[0] - size - 2)
			write(1, " ", 1);
	return (ft_uhexlen(adrs) + 2 + (--j) + (i ? --i : i));
}

int				ft_percent_p(void *ptr)
{
	unsigned long	adrs;
	int				i;

	i = 0;
	if (var.flag[1])
		return (ft_dot_flag(ptr, i));
	adrs = (unsigned long)ptr;
	if (var.flag[0] == 3)
		while (i++ < var.prec[0] - ft_uhexlen(adrs) - 2)
			write(1, " ", 1);
	ft_putstr_fd("0x", 1);
	if (var.flag[0] == 1 || var.flag[0] == 4)
		while (i++ < var.prec[0] - ft_uhexlen(adrs) - 2)
			write(1, "0", 1);
	ft_percent_x_remix(adrs);
	if (var.flag[0] == 2)
		while (i++ < var.prec[0] - ft_uhexlen(adrs) - 2)
			write(1, " ", 1);
	return (ft_uhexlen(adrs) + 2 + (i ? --i : i));
}
