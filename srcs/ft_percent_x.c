/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:10:22 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/05 15:16:07 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_percent_x(unsigned int n)
{
	char	*base;

	base = "0123456789abcdef";
	if (n > 15)
		ft_percent_x(n / 16);
	ft_putchar_fd(base[n % 16], 1);
	return (0);
}
