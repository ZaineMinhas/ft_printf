/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_d_and_i.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:31:21 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/25 17:34:29 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int		ft_dot_flag(unsigned int nb, int i, int pos_neg)
{
	int size;
	int j;

	j = 0;
	size = g_prec[1] < ft_intlen_ui(nb) ? ft_intlen_ui(nb) : g_prec[1];
	!(!nb && g_prec[1] == 0) ? write(1, "", 0) : size--;
	if (g_flag[0] == 1 || g_flag[0] == 3)
		while (i++ < g_prec[0] - size - pos_neg)
			write(1, " ", 1);
	if (pos_neg)
		write(1, "-", 1);
	while (j++ < g_prec[1] - ft_intlen_ui(nb))
		write(1, "0", 1);
	!(!nb && g_prec[1] == 0) ? ft_putnbr_remix(nb) : write(1, "", 0);
	if (g_flag[0] == 2)
		while (i++ < g_prec[0] - size - pos_neg)
			write(1, " ", 1);
	return (size + (i ? --i : i) + pos_neg);
}

static int		ft_first_flag(unsigned int nb, int i, int pos_neg)
{
	if (g_flag[0] == 3)
		while (i++ < g_prec[0] - ft_intlen_ui(nb) - pos_neg)
			write(1, " ", 1);
	if (pos_neg)
		write(1, "-", 1);
	if (g_flag[0] == 1)
		while (i++ < g_prec[0] - ft_intlen_ui(nb) - pos_neg)
			write(1, "0", 1);
	else if (g_flag[0] == 4)
	{
		if (pos_neg)
			while (i++ < g_prec[0] - ft_intlen_ui(nb))
				write(1, "0", 1);
		else
			while (i++ < g_prec[0] - ft_intlen_ui(nb) - pos_neg)
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
	}
	else
		nb = n;
	size = ft_intlen_ui(nb) + pos_neg;
	if (g_flag[1])
		return (ft_dot_flag(nb, i, pos_neg));
	i = ft_first_flag(nb, i, pos_neg);
	!(!nb && g_flag[0] == 4 && g_prec[0] == 0) ?
	ft_putnbr_remix(nb) : size--;
	if (g_flag[0] == 2)
		while (i++ < g_prec[0] - ft_intlen_ui(nb) - pos_neg)
			write(1, " ", 1);
	return (size + (i ? --i : i));
}
