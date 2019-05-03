/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:52:17 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/11 11:54:40 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list	*elem;

	if (!(begin_list))
		return (NULL);
	elem = begin_list;
	while (nbr > 1)
	{
		if (!elem)
			return (NULL);
		elem = elem->next;
		nbr--;
	}
	return (elem);
}
