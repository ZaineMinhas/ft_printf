/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 14:42:53 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/14 15:14:20 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_add_front(char *str, int add)
{
	char	*dest;
	int		size;
	int		i;
	int		j;

	size = ft_strlen(str) + 1 + add;
	if (!(dest = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	i = 0;
	while (add--)
		dest[i] = var.add_char;
	j = -1;
	while (str[++j])
		dest[i++] = str[j];
	dest[size] = 0;
	return (dest);
}

char	*ft_add_back(char *str, int add)
{
	char	*dest;
	int		size;
	int		i;
	int		j;

	size = ft_strlen(str) + 1 + add;
	if (!(dest = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	i = -1;
	while (str[++i])
		dest[i] = str[i];
	while (dest[i++])
		dest[i] = var.add_char;
	dest[size] = 0;
	return (dest);
}
