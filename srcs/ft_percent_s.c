/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:54:26 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/18 14:48:04 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_put_size_str(char *s, int size)
{
	if (!size)
		size = ft_strlen(s);
	write(1, s, size);
	return (size);
}

static int	ft_dot_flag(char *str)
{
	int i;

	if (!var.flag[1])
	{
		ft_put_size_str(str, var.prec[0]);
		return (var.prec[0]);
	}
	else
	{
		i = 0;
		if (var.flag[0] == 3)
			while (i++ < var.prec[0] - ft_strlen(str))
				write(1, " ", 1);
		else if (var.flag[0] == 1)
			while (i++ < var.prec[0] - ft_strlen(str))
				write(1, "0", 1);
		i += ft_put_size_str(str, var.prec[1]);
		if (var.flag[0] == 2)
			while (i++ < var.prec[0] - ft_strlen(str))
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
	return (ft_strlen(str));
}
