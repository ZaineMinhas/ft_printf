/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:54:26 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/21 19:41:09 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_put_dotsize_str(char *s, int prec)
{
	int size;

	size = prec < (int)ft_strlen(s) ? prec : ft_strlen(s);
	write(1, s, size);
	return (size);
}

static int	ft_put_dotsize_str_remix(char *s, int prec)
{
	int size;

	size = prec < (int)ft_strlen(s) ? prec : ft_strlen(s);
	write(1, s, size);
	if (size != (int)ft_strlen(s))
		return (size - ft_strlen(s));
	return (size);
}

static int	ft_dot_flag(char *s, int i)
{
	int size;

	size = var.prec[1] < (int)ft_strlen(s) ? var.prec[1] : ft_strlen(s);
	if (var.flag[0] == 1)
		while (i++ < var.prec[0] - size)
			write(1, "0", 1);
	else if (var.flag[0] == 3)
		while (i++ < var.prec[0] - size)
			write(1, " ", 1);
	size = ft_put_dotsize_str(s, var.prec[1]);
	if (var.flag[0] == 2)
		while (i++ < var.prec[0] - size)
			write(1, " ", 1);
	return (size + (i ? --i : i));
}

int			ft_percent_s(char *str)
{
	int size;
	int i;

	i = 0;
	size = 0;
	if (var.flag[1])
		return (ft_dot_flag(str, i));
	else if (var.flag[0] == 4)
		size = ft_put_dotsize_str_remix(str, var.prec[0]);
	else if (var.flag[0] == 1)
		while (i++ < var.prec[0] - (int)ft_strlen(str))
			write(1, "0", 1);
	else if (var.flag[0] == 3)
		while (i++ < var.prec[0] - (int)ft_strlen(str))
			write(1, " ", 1);
	if (var.flag[0] != 4)
		ft_putstr_fd(str, 1);
	if (var.flag[0] == 2)
		while (i++ < var.prec[0] - (int)ft_strlen(str))
			write(1, " ", 1);
	return (ft_strlen(str) + size + (i ? --i : i));
}
