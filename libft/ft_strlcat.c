/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:24:21 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/11 12:57:10 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	a;

	i = 0;
	j = 0;
	a = ft_strlen(dst);
	i = a;
	if (size <= a)
		return (size + ft_strlen(src));
	while (src[j] != '\0' && j < (size - a - 1))
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (a + ft_strlen(src));
}
