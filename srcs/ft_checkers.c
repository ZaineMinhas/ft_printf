/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 18:36:31 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/05 19:11:17 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_flag_checker(const char *format)
{
	int i;

	i = 0;
	if (format[i] == '0')
		list.the_flag[0] = 1;
	else if (format[i] == '-')
		list.the_flag[0] = 2;
	else if (format[i] == '*' || ft_isdigit((int)format[i]))
		list.the_flag[0] = 3;
	else if (format[i] == '.')
		list.the_flag[0] = 4;
	if (list.the_flag[0])
		i++;
	while (ft_isdigit((int)format[i]) ||\
	(format[i] == '*' && format[i + 1] != '*'))
		i++;
	if (format[i] == '.' && list.the_flag[0] != 4)
		list.the_flag[1] = 4;
	return (0);
}
