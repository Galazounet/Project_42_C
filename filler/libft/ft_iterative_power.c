/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:28:34 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/11 16:28:44 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

int		ft_iterative_power(int nb, int power)
{
	int		n;

	n = nb;
	if (nb == 0 || power < 0)
		return (0);
	if (power == 0)
		return (nb > 0 ? 1 : -1);
	while (power > 1)
	{
		nb = nb * n;
		power--;
	}
	return (nb);
}
