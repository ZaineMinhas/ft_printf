/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_d_and_i.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:31:21 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/20 19:21:36 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int ft_dot_flag(int n)
{
	int	i;
	int j;
	int	size;

	i = 0;
	j = 0;
	size = var.prec[1] > ft_intlen(n) ? var.prec[1] : ft_intlen(n);
	if (var.flag[0] == 3 || var.flag[0] == 1)
		while (i++ < var.prec[0] - size)
			write(1, " ", 1);
	while (j++ < (var.prec[1] - ft_intlen(n)))
		write(1, "0", 1);
	ft_putnbr_fd(n, 1);
	if (var.flag[0] == 2)
		while (i++ < var.prec[0] - size)
			write(1, " ", 1);
	return (size + (i ? --i : i));
}

int		ft_percent_d_and_i(int n)
{
	int i;

	if (var.flag[1])
		return (ft_dot_flag(n));
	i = 0;
	if (var.flag[0] == 1 || var.flag[0] == 4)
		while (i++ < (var.prec[0] - ft_intlen(n)))
			write(1, "0", 1);
	else if (var.flag[0] == 3)
		while (i++ < (var.prec[0] - ft_intlen(n)))
			write(1, " ", 1);
	ft_putnbr_fd(n, 1);
	if (var.flag[0] == 2)
		while (i++ < (var.prec[0] - ft_intlen(n)))
			write(1, " ", 1);
	return (ft_intlen(n) + (i ? --i : i));
}
