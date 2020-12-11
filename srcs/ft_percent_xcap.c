/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_xcap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:34:00 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/11 13:23:16 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_percent_xcap(unsigned int n)
{
	char	*base;
	char	*res;
	int		power;
	int		i;

	base = "0123456789ABCDEFf";
	power = ft_hexlen(n);
	if (!(res = ft_calloc(sizeof(char), (power + 1))))
		return (0);
	i = power;
	while (power--)
	{
		res[power] = base[n % 16];
		n /= 16;
	}
	ft_putstr_fd(res, 1);
	return (i);
}
