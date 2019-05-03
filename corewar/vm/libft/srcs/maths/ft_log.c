/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:24:49 by afrangio          #+#    #+#             */
/*   Updated: 2018/04/20 13:48:07 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

uintmax_t	ft_log(intmax_t n, int b)
{
	uintmax_t len;

	if (!n)
		return (1);
	len = 0;
	if (n < 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n /= b;
	}
	return (len);
}
