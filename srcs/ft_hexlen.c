/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 17:20:07 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/25 17:44:03 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_hexlen(unsigned int n)
{
	int len;

	len = 0;
	while (n /= 16)
		len++;
	return (++len);
}

int	ft_hexlen_ul(unsigned long n)
{
	int len;

	len = 0;
	while (n /= 16)
		len++;
	return (++len);
}
