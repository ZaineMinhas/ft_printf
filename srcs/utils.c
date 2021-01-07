/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:34:59 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/07 19:35:31 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_ispercent(const char *format, int index)
{
	if (format[index] == 'c' || format[index] == 'd' ||\
	format[index] == 'i' || format[index] == 'p' || format[index] == 's' ||\
	format[index] == 'u' || format[index] == 'x' || format[index] == 'X')
		return (1);
	return (0);
}
