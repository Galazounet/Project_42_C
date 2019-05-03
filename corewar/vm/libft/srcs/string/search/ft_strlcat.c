/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:16:18 by afrangio          #+#    #+#             */
/*   Updated: 2018/11/16 19:04:30 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	while (dst[i] && i < size)
		i++;
	j = 0;
	if (size > 0)
	{
		while (src[j] && i < size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
	}
	if (j > 0)
	{
		dst[i] = '\0';
		return (ft_strlen(src) + i - j);
	}
	return (ft_strlen(src) + i);
}

void	ft_memlcat(void *dst, const void *src, size_t start, size_t size)
{
	size_t j;

	j = 0;
	if (size > 0)
	{
		while (start < size - 1)
		{
			((char*)dst)[start] = ((char*)src)[j];
			start++;
			j++;
		}
	}
	if (j > 0)
		((char*)dst)[start] = '\0';
}
