/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_xcap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:34:00 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/02 15:36:43 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_convert_xcap(unsigned int n)
{
	char *base;

	base = "0123456789abcdef";
	ft_putchar_fd(base[n / 16], 1);
	ft_putchar_fd(base[n % 16], 1);
	return (0);
}
