/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:10:22 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/02 17:35:29 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_convert_x(unsigned int n)
{
	char *base;

	base = "0123456789abcdef";
	if (n)
	{
		ft_convert_x(n / 16);
		ft_putchar_fd(base[n % 16], 1);
	}
	return (0);
}
