/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:54:26 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/20 15:00:20 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_put_dotsize_str(char *s, int index)
{
	int size;

	size = var.prec[index] < (int)ft_strlen(s) ? ft_strlen(s) : var.prec[index];
	write(1, s, size);
	return (size);
}

static int	ft_dot_flag(char *str)
{
	int i;
	int size;

	if (!var.flag[1])
		return (ft_put_dotsize_str(str, 0));
	else
	{
		i = 0;
		size = var.prec[1] < (int)ft_strlen(str) ? ft_strlen(str) : var.prec[1];
		if (var.flag[0] == 3)
			while (i++ < var.prec[0] - ((int)ft_strlen(str) + size))
				write(1, " ", 1);
		else if (var.flag[0] == 1)
			while (i++ < var.prec[0] - ((int)ft_strlen(str) + size))
				write(1, "0", 1);
		i += ft_put_dotsize_str(str, 1);
		if (var.flag[0] == 2)
			while (i++ < var.prec[0] - ((int)ft_strlen(str)))
				write(1, " ", 1);
		return (i);
	}
}

int			ft_percent_s(char *str)
{
	int i;

	i = 0;
	if (var.flag[0] == 4 || var.flag[1])
		return (ft_dot_flag(str));
	if (var.flag[0] == 1)
		while (i++ < var.prec[0] - (int)ft_strlen(str))
			write(1, "0", 1);
	else if (var.flag[0] == 3)
		while (i++ < var.prec[0] - (int)ft_strlen(str))
			write(1, " ", 1);
	ft_putstr_fd(str, 1);
	if (var.flag[0] == 2)
		while (i++ < var.prec[0] - (int)ft_strlen(str))
			write(1, " ", 1);
	return (ft_strlen(str) + i);
}
