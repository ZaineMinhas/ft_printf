/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:13:09 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/05 19:12:17 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static	int		ft_hexlen_remix(unsigned long n)
{
	int len;

	len = 0;
	while (n /= 16)
		len++;
	return (++len);
}

static	int		ft_percent_x_remix(unsigned long n)
{
	char	*base;
	char	*res;
	int		power;
	int		i;

	base = "0123456789abcdef";
	power = ft_hexlen_remix(n);
	if (!(res = ft_calloc(sizeof(char), (power + 1))))
		return (0);
	i = ft_hexlen_remix(n);
	while (power--)
	{
		res[power] = base[n % 16];
		n /= 16;
	}
	ft_putstr_fd(res, 1);
	return (i);
}

int				ft_percent_p(void *ptr)
{
	unsigned long	adrs;

	adrs = (unsigned long)ptr;
	ft_putstr_fd("0x", 1);
	return (ft_percent_x_remix(adrs) + 2);
}
