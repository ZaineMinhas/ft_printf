/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_xcap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:34:00 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/02 18:08:53 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_convert_xcap(unsigned int n)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (n > 15)
		ft_convert_xcap(n / 16);
	ft_putchar_fd(base[n % 16], 1);
	return (0);
}
