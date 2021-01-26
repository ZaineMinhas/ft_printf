/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:34:59 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/26 17:10:54 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_ispercent(int c)
{
	if (c == 'c')
		return (1);
	if (c == 'd' || c == 'i')
		return (2);
	if (c == 'p')
		return (3);
	if (c == 's')
		return (4);
	if (c == 'u')
		return (5);
	if (c == 'x')
		return (6);
	if (c == 'X')
		return (7);
	if (c == '%')
		return (8);
	return (0);
}

void	ft_ajust_var(void)
{
	if (g_flag[0])
	{
		if ((g_flag[0] == 1 || g_flag[0] == 3) && g_prec[0] < 0)
		{
			g_flag[0] = 2;
			g_prec[0] *= -1;
		}
		if (g_flag[0] == 2 && g_prec[0] < 0)
		{
			g_flag[0] = 2;
			g_prec[0] *= -1;
		}
		if (g_flag[0] == 4 && g_prec[0] < 0)
			g_prec[0] = -1;
	}
	if (g_flag[1] == 4 && g_prec[1] < 0)
		g_prec[1] = -1;
	if (g_flag[1] && g_flag[1] != 4)
	{
		g_flag[1] = 0;
		g_prec[0] = g_prec[1];
	}
}

void	ft_second_ajust(void)
{
	if (g_prec[0] < 0)
	{
		g_flag[0] = 0;
		g_prec[0] = 0;
	}
	if (g_prec[1] < 0)
	{
		g_flag[1] = 0;
		g_prec[1] = 0;
	}
}

int		ft_atoi_remix(const char **str)
{
	unsigned long long		nb;
	unsigned long long		nb_tmp;
	int						pos_neg;

	pos_neg = 1;
	while (*(*str) == '-' || *(*str) == '0')
	{
		if (*(*str) == '-')
			pos_neg = -1;
		(*str)++;
	}
	if (*(*str) == '*')
	{
		(*str)++;
		return (va_arg(g_args, int));
	}
	nb = 0;
	while (*(*str) >= '0' && *(*str) <= '9' && *(*str))
	{
		nb_tmp = nb;
		nb = nb * 10 + (*(*str)++ - 48);
		if (nb < nb_tmp || nb > LLONG_MAX)
			return ((pos_neg == 1) ? -1 : 0);
	}
	return ((int)nb * pos_neg);
}
