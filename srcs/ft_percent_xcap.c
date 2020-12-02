/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_xcap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:34:00 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/02 17:04:19 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_convert_xcap(unsigned int n)
{
	char *base;

	base = "0123456789ABCDEF";
	if (n)
	{
		ft_convert_xcap(n / 16);
		ft_putchar_fd(base[n % 16], 1);
	}
	return (0);
}
