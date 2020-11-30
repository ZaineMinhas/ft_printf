/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:49:08 by zminhas           #+#    #+#             */
/*   Updated: 2020/11/25 14:26:36 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_is_set(char const c, char const *set)
{
	while (*set)
		if (*set++ == c)
			return (1);
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;

	if (!s1)
		return (NULL);
	i = 0;
	while (s1[i] && ft_is_set(s1[i], set))
		i++;
	j = ft_strlen(s1) - 1;
	while (j >= i && ft_is_set(s1[j], set))
		j--;
	return (ft_substr(s1, i, j - i + 1));
}
