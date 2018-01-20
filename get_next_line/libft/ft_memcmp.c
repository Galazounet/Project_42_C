/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:46:29 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/11 10:38:50 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str_1;
	unsigned char	*str_2;
	size_t			i;

	i = 0;
	str_1 = (unsigned char*)s1;
	str_2 = (unsigned char*)s2;
	if (n == 0)
		return (0);
	while (i < (n - 1) && str_1[i] == str_2[i])
		i++;
	if (str_1[i] != str_2[i])
		return (str_1[i] - str_2[i]);
	return (0);
}
