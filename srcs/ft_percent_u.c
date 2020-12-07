/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_u.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 17:20:37 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/07 17:09:52 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <stdio.h>

static	void	ft_putnbr_remix(unsigned int n)
{
	unsigned int	nb;

	if (n < 0)
	{
		write(1, "-", 1);
		nb = -n;
	}
	else
		nb = n;
	if (nb > 9)
		ft_putnbr_remix(nb / 10);
	ft_putchar_fd(48 + nb % 10, 1);
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
