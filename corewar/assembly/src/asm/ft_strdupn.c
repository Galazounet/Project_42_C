/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdupn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 02:12:42 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:00:31 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*ft_strdupn(char *str, size_t n)
{
	char *dest;

	if (!str || n == 0)
		return (NULL);
	if (!(dest = ft_strnew(n + 1)))
		return (NULL);
	ft_strncpy(dest, str, n);
	return (dest);
}
