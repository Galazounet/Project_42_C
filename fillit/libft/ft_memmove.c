/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:19:47 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/11 10:39:03 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*str_d;
	char	*str_s;
	size_t	i;

	i = 0;
	str_d = (char *)dst;
	str_s = (char*)src;
	if (str_d > str_s)
	{
		while (i < len)
		{
			str_d[len - 1] = str_s[len - 1];
			len--;
		}
		return (dst);
	}
	else
	{
		while (i < len)
		{
			str_d[i] = str_s[i];
			i++;
		}
		return (dst);
	}
}
