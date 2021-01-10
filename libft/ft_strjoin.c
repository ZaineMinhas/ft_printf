/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 13:38:42 by zminhas           #+#    #+#             */
/*   Updated: 2021/01/10 19:16:00 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	size;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(dest = (char *)ft_calloc(sizeof(char), size)))
	{
		free((void *)s1);
		return (NULL);
	}
	ft_memcpy(dest, s1, ft_strlen(s1));
	ft_memcpy(dest + ft_strlen(s1), s2, ft_strlen(s2));
	free((void *)s1);
	return (dest);
}
