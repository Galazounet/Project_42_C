/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:11:38 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/11 10:37:57 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*str_s;
	size_t	i;

	str_s = (char*)s;
	i = 0;
	while (n > i)
		str_s[i++] = '\0';
}
