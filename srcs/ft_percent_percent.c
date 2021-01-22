/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_percent.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 19:09:49 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/22 20:18:10 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_percent_percent(void)
{
	int i;

	i = 0;
	if (var.flag[0] == 1)
		while (i++ < var.prec[0] - 1)
			write(1, "0", 1);
	else if (var.flag[0] == 3)
		while (i++ < var.prec[0] - 1)
			write(1, " ", 1);
	write(1, "%", 1);
	if (var.flag[0] == 2)
		while (i++ < var.prec[0] - 1)
			write(1, " ", 1);
	return (1 + (i ? --i : i));
}
