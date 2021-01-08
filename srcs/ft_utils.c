/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:34:59 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/08 14:25:38 by zminhas          ###   ########.fr       */
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

int	ft_atoi_remix(const char *str)
{
	unsigned long long		nb;
	unsigned long long		nb_tmp;
	int						pos_neg;
	int						i;

	i = 0;
	pos_neg = 1;
	if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			pos_neg = -1;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		nb_tmp = nb;
		nb = nb * 10 + (str[i++] - 48);
		if (nb < nb_tmp || nb > LLONG_MAX)
			return ((pos_neg == 1) ? -1 : 0);
	}
	if ((str[0] == '0' && ((int)nb * pos_neg) > 0) ||\
	(str[1] == '0' && ((int)nb * pos_neg) < 0))
		return (-1);
	return ((int)nb * pos_neg);
}
