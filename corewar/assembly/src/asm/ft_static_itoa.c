/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_static_itoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:12:14 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:02:13 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*ft_static_itoa(int n)
{
	static char		s[15];
	int				i;
	long			k;

	k = n;
	ft_memset(s, 0, 15);
	i = (k < 0) ? ft_intlen(k) : ft_intlen(k) - 1;
	if (k < 0)
	{
		s[0] = '-';
		i--;
		k *= -1;
	}
	else if (k == 0)
		s[0] = '0';
	while (k > 0)
	{
		s[i] = (k % 10) + 48;
		k /= 10;
		i--;
	}
	return (s);
}
