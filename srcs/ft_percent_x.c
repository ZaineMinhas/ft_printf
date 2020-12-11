/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 15:10:22 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/11 13:23:20 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_percent_x(unsigned int n)
{
	char	*base;
	char	*res;
	int		power;
	int		i;

	base = "0123456789abcdef";
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
