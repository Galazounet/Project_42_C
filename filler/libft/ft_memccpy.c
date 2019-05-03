/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:34:52 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/11 17:56:36 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	const unsigned char	*str_s;
	unsigned char		*str_d;
	unsigned char		d;

	if (n)
	{
		str_d = dst;
		str_s = src;
		d = c;
		++n;
		while (--n != 0)
		{
			if ((*str_d++ = *str_s++) == d)
				return (str_d);
		}
	}
	return (0);
}
