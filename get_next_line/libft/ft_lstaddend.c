/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:37:59 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/11 11:46:43 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstaddend(t_list *lst, t_list *last)
{
	t_list *tmp;

	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = last;
}
