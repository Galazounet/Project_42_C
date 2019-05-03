/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 01:48:24 by suddin            #+#    #+#             */
/*   Updated: 2018/10/06 01:48:34 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	string_join(char **dest, char *src, int src_len)
{
	char *tmp;

	if (!src || !dest)
		return ;
	tmp = NULL;
	if (!*dest)
		*dest = ft_strdupn(src, src_len);
	else
	{
		tmp = *dest;
		*dest = ft_strnew(ft_strlen(*dest) + src_len);
		ft_strcpy(*dest, tmp);
		ft_strncat(*dest, src, src_len);
		ft_memdel((void*)&tmp);
	}
}
