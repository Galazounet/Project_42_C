/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulog.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 19:14:29 by afrangio          #+#    #+#             */
/*   Updated: 2018/04/20 14:13:40 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	ft_ulog(uintmax_t n, uintmax_t b)
{
	uintmax_t len;

	if (!n)
		return (1);
	len = 0;
	while (n != 0)
	{
		len++;
		n /= b;
	}
	return (len);
}
