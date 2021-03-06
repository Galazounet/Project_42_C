/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 10:56:42 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/11 11:01:22 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_sqrt(int nb)
{
	int		i;

	i = 0;
	if (nb <= 0)
		return (0);
	while ((i * i) < nb)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}
