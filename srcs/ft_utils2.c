/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:42:53 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/20 15:17:00 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_second_ajust(void)
{
	if (var.prec[0] < 0)
	{
		var.flag[0] = 0;
		var.prec[0] = 0;
	}
	if (var.prec[1] < 0)
	{
		var.flag[1] = 0;
		var.prec[1] = 1;
	}
}

void	ft_pass(const char **str)
{
	while (ft_isdigit((int)*(*str)) || *(*str) == '-' || *(*str) == '*' || *(*str) == '.')
		(*str)++;
}
