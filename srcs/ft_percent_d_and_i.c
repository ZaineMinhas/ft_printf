/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_d_and_i.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:31:21 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/24 16:49:21 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	void	ft_putnbr_remix(unsigned int n)
{
	if (n > 9)
		ft_putnbr_remix(n / 10);
	ft_putchar_fd(48 + n % 10, 1);
}

static int		ft_dot_flag(unsigned int nb, int i, int pos_neg)
{
	int size;
	int j;

	j = 0;
	size = var.prec[1] < ft_intlen(nb) ? ft_intlen(nb) : var.prec[1];
	!(!nb && var.prec[1] == 0) ? write(1, "", 0) : size--;
	if (var.flag[0] == 1 || var.flag[0] == 3)
		while (i++ < var.prec[0] - size)
			write(1, " ", 1);
	if (pos_neg)
		write(1, "-", 1);
	while (j++ < var.prec[1] - ft_intlen(nb))
		write(1, "0", 1);
	!(!nb && var.prec[1] == 0) ? ft_putnbr_remix(nb) : write(1, "", 0);
	if (var.flag[0] == 2)
		while (i++ < var.prec[0] - size)
			write(1, " ", 1);
	return (size + (i ? --i : i));
}

static int		ft_first_flag(unsigned int nb, int i, int pos_neg)
{
	if (var.flag[0] == 3)
		while (i++ < var.prec[0] - ft_intlen(nb))
			write(1, " ", 1);
	if (pos_neg)
		write(1, "-", 1);
	if (var.flag[0] == 1)
		while (i++ < var.prec[0] - ft_intlen(nb))
			write(1, "0", 1);
	else if (var.flag[0] == 4)
	{
		if (pos_neg)
			while (i++ < var.prec[0] - ft_intlen(nb) + 1)
				write(1, "0", 1);
		else
			while (i++ < var.prec[0] - ft_intlen(nb))
				write(1, "0", 1);
	}
	return (i);
}

int				ft_percent_d_and_i(int n)
{
	unsigned int	nb;
	int				pos_neg;
	int				size;
	int				i;

	i = 0;
	pos_neg = 0;
	if (n < 0)
	{
		nb = (unsigned int)-n;
		pos_neg = 1;
		i++;
	}
	else
		nb = n;
	size = ft_intlen(nb) + pos_neg;
	if (var.flag[1])
		return (ft_dot_flag(nb, i, pos_neg));
	i = ft_first_flag(nb, i, pos_neg);
	!(!nb && var.flag[0] == 4 && var.prec[0] == 0) ? ft_putnbr_remix(nb) : size--;
	if (var.flag[0] == 2)
		while (i++ < var.prec[0] - ft_intlen(nb))
			write(1, " ", 1);
	return (size + (i ? --i : i));
}
