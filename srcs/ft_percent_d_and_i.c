/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_d_and_i.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:31:21 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/21 16:20:06 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	void	ft_putnbr_remix(unsigned int n)
{
	if (n > 9)
		ft_putnbr_remix(n / 10);
	ft_putchar_fd(48 + n % 10, 1);
}

static int		ft_dot_flag(int n)
{
	int	i;
	int j;
	int	size;

	i = 0;
	j = 0;
	size = var.prec[1] > ft_intlen(n) ? var.prec[1] : ft_intlen(n);
	size = n < 0 ? size + 1 : size;
	if (var.flag[0] == 3 || var.flag[0] == 1)
		while (i++ < var.prec[0] - size)
			write(1, " ", 1);
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	while (j++ < (var.prec[1] - ft_intlen(n)))
		write(1, "0", 1);
	ft_putnbr_remix(n);
	if (var.flag[0] == 2)
		while (i++ < var.prec[0] - size)
			write(1, " ", 1);
	return (size + (i ? --i : i));
}

static int	ft_dot_and_zero(unsigned int *nb, int n, int i)
{
	int pos_neg;

	pos_neg = 0;
	if (n < 0)
	{
		i++;
		*nb = (unsigned int)-n;
		pos_neg++;
		write(1, "-", 1);
	}
	if (var.flag[0] == 1)
		while (i++ < (var.prec[0] - ft_intlen(*nb)))
			write(1, "0", 1);
	else if (var.flag[0] == 4)
	{
		if (pos_neg)
			while (i++ < var.prec[0] - ft_intlen(*nb) + 1)
				write(1, "0", 1);
		else
			while (i++ < var.prec[0] - ft_intlen(*nb))
				write(1, "0", 1);
	}
	return (i);
}

int			ft_percent_d_and_i(int n)
{
	int i;
	unsigned int nb;

	if (var.flag[1])
		return (ft_dot_flag(n));
	i = 0;
	if (var.flag[0] == 3)
		while (i++ < (var.prec[0] - ft_intlen(n)))
			write(1, " ", 1);
	i += ft_dot_and_zero(&nb, n, i);
	ft_putnbr_remix(nb);
	if (var.flag[0] == 2)
		while (i++ < (var.prec[0] - ft_intlen(n)))
			write(1, " ", 1);
	return (ft_intlen(n) + (i ? --i : i));
}
