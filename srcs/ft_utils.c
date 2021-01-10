/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 18:34:59 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/10 19:24:49 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int		ft_ispercent(int c)
{
	if (c == 'c')
		return (1);
	if (c == 'd' || c == 'i')
		return (2);
	if (c == 'p')
		return (3);
	if (c == 's')
		return (4);
	if (c == 'u')
		return (5);
	if (c == 'x')
		return (6);
	if (c == 'X')
		return (7);
	if (c == '%')
		return (8);
	return (0);
}

int        ft_index(char *s, char c)
{
    int i;

    if (!s)
        return (-1);
    i = -1;
    while (s[++i] && !ft_ispercent((int)s[i]))
        if (s[i] == c)
            return (i);
    return ((s[i] == c) ? i : -1);
}

char	*ft_char_trans(const char *format)
{
	char	*s1;

	if (!(s1 = ft_substr(format, 0, ft_index(format, '*'))))
		return (NULL);
	if (!(s1 = ft_strjoin(s1, ft_itoa(va_arg(var.args, int)))))	
		return (NULL);
	if (!(s1 = ft_strjoin(s1, ft_strchr(format, '*') + 1)))
		return (NULL);
	return (s1);
}

int		ft_atoi_remix(const char *str)
{
	unsigned long long		nb;
	unsigned long long		nb_tmp;
	int						pos_neg;
	int						i;

	if (str[0] == '0' || str[0] == '-')
		return (-1);
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
	return ((int)nb * pos_neg);
}
