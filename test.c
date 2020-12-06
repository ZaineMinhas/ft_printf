/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 16:32:59 by zminhas           #+#    #+#             */
/*   Updated: 2020/12/06 17:50:49 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	printf("%d\n", printf("%x\n", -10));
	printf("%d\n", ft_hexlen(-10));
	ft_printf("mon chiffre prefere est le : %x et le : %X\n", 10, -10);
	return (0);
}