/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:44:19 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/11 10:40:33 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * size + 1)))
		return (0);
	ft_bzero(str, size + 1);
	return (str);
}
