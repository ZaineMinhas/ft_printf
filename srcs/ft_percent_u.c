/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:20:37 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/24 15:33:34 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	void	ft_putnbr_remix(unsigned int n)
{
	if (n > 9)
		ft_putnbr_remix(n / 10);
	ft_putchar_fd(48 + n % 10, 1);
}

static	int		ft_intlen_remix(unsigned int n)
{
	int	len;

	len = (n < 0) ? 1 : 0;
	while (n /= 10)
		len++;
	return (++len);
}

static int		ft_put_ui_nbr(int n)
{
	if (n > 0)
	{
		ft_putnbr_fd(n, 1);
		return (ft_intlen(n));
	}
	ft_putnbr_remix(UINT_MAX + n + 1);
	return (ft_intlen_remix(UINT_MAX + n + 1));
}

static int		ft_dot_flag(int n, int i)
{
	int size;
	int j;

	j = 0;
	size = var.prec[1] < ft_intlen_remix(n) ? ft_intlen_remix(n) : var.prec[1];
	!(!n && var.prec[1] == 0) ? write(1, "", 0) : i--;
	if ((var.flag[0] == 1 || var.flag[0] == 3))
		while (i++ < var.prec[0] - size)
			write(1, " ", 1);
	while (j++ < var.prec[1] - ft_intlen_remix(n))
		write(1, "0", 1);
	!(!n && var.prec[1] == 0) ? ft_put_ui_nbr(n) : write(1, "", 0);
	if (var.flag[0] == 2)
		while (i++ < var.prec[0] - size)
			write(1, " ", 1);
	var.prec[0] == 0 && var.prec[1] == 0 ? i-- : write(1, "", 0);
	return (ft_intlen_remix(UINT_MAX + n + 1) + (i > 0 ? --i : i) + (--j));
}

int				ft_percent_u(int n)
{
	int size;
	int i;

	i = 0;
	if (var.flag[1])
		return (ft_dot_flag(n, i));
	size = ft_intlen_remix(UINT_MAX + n + 1);
	if (var.flag[0] == 1 || var.flag[0] == 4)
		while (i++ < var.prec[0] - ft_intlen_remix(n))
			write(1, "0", 1);
	else if (var.flag[0] == 3)
		while (i++ < var.prec[0] - ft_intlen_remix(n))
			write(1, " ", 1);
	!(!n && var.flag[0] == 4 && var.prec[0] == 0) ? ft_put_ui_nbr(n) : size--;
	if (var.flag[0] == 2)
		while (i++ < var.prec[0] - ft_intlen_remix(n))
			write(1, " ", 1);
	return (size + (i ? --i : i));
}
