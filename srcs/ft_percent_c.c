/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:29:55 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/25 17:33:48 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_percent_c(int c)
{
	int	i;

	i = 0;
	if (g_flag[0] == 1)
		while (i++ < g_prec[0] - 1)
			write(1, "0", 1);
	else if (g_flag[0] == 3)
		while (i++ < g_prec[0] - 1)
			write(1, " ", 1);
	write(1, &c, 1);
	if (g_flag[0] == 2)
		while (i++ < g_prec[0] - 1)
			write(1, " ", 1);
	return (i ? i : ++i);
}
