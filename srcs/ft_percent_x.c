/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:10:22 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/22 14:13:50 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_putnbr_x(unsigned int n, char *base)
{
	char	*res;
	int		power;
	int		i;

	power = ft_hexlen(n);
	if (!(res = ft_calloc(sizeof(char), (power + 1))))
		return (0);
	i = power;
	while (power--)
	{
		res[power] = base[n % 16];
		n /= 16;
	}
	ft_putstr_fd(res, 1);
	return (i);
}

static	int	ft_dot_flag(unsigned int n, char *base, int i)
{
	int size;
	int j;

	j = 0;
	size = var.prec[1] < ft_hexlen(n) ? ft_hexlen(n) : var.prec[1];
	if (var.flag[0] == 1 || var.flag[0] == 3)
		while (i++ < var.prec[0] - size)
			write(1, " ", 1);
	while (j++ < var.prec[1] - ft_hexlen(n))
		write(1, "0", 1);
	ft_putnbr_x(n, base);
	if (var.flag[0] == 2)
		while (i++ < var.prec[0] - size)
			write(1, " ", 1);
	return (size + (i ? --i : i));
	
}

int		ft_percent_x(unsigned int n, char *base)
{
	int i;

	i = 0;
	if (var.flag[1])
		return (ft_dot_flag(n, base, i));
	if (var.flag[0] == 1 || var.flag[0] == 4)
		while (i++ < var.prec[0] - ft_hexlen(n))
			write(1, "0", 1);
	else if (var.flag[0] == 3)
		while (i++ < var.flag[0] - ft_hexlen(n))
			write(1, " ", 1);
	ft_putnbr_x(n, base);
	if (var.flag[0] == 2)
		while (i++ < var.prec[0] - ft_hexlen(n))
			write(1, " ", 1);
	return (ft_hexlen(n) + (i ? --i : i));
}
