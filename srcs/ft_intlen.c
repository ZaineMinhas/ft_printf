/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 17:03:36 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/06 16:49:07 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_intlen(int n)
{
	unsigned long int	len;

	len = (n < 0) ? 1 : 0;
	while (n /= 10)
		len++;
	return (++len);
}
