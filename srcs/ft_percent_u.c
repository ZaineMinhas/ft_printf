/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:20:37 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/21 16:00:04 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

static	void	ft_putnbr_remix(unsigned int n)
{
	if (n > 9)
		ft_putnbr_remix(n / 10);
	ft_putchar_fd(48 + n % 10, 1);
}

static	int		ft_intlen_remix(unsigned int n)
{
	int	len;

	len = (n < 0) ? 1 : 0;
	while (n /= 10)
		len++;
	return (++len);
}

int				ft_percent_u(int n)
{
	if (n > 0)
	{
		ft_putnbr_fd(n, 1);
		return (ft_intlen(n));
	}
	ft_putnbr_remix(UINT_MAX + n + 1);
	return (ft_intlen_remix(UINT_MAX + n + 1));
}
