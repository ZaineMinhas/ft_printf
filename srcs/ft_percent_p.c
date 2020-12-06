/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_percent_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 15:13:09 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/06 16:28:07 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_percent_p(void *ptr)
{
	int	adrs;
	int i;

	i = 6;
	adrs = (int)ptr;
	ft_putstr_fd("0x7ffe", 1);
	i += ft_percent_x(adrs);
	return (i);
}
