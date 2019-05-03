/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:17:12 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/11 10:38:55 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*str_d;
	char	*str_s;
	size_t	i;

	i = 0;
	str_d = (char*)dest;
	str_s = (char*)src;
	while (n > i)
	{
		str_d[i] = str_s[i];
		i++;
	}
	return (dest);
}
