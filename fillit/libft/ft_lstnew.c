/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:33:11 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/10 17:59:00 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	if (!(elem = malloc(sizeof(*elem))))
		return (NULL);
	elem->next = NULL;
	if (!content)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		elem->content_size = content_size;
		elem->content = malloc(sizeof(t_list) * content_size);
		ft_memcpy(elem->content, content, content_size);
	}
	return (elem);
}
