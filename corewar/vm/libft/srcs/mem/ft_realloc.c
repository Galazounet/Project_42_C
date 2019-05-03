/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 02:22:49 by afrangio          #+#    #+#             */
/*   Updated: 2018/11/16 18:49:42 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(char *mem, size_t size)
{
	char *temp;

	temp = ft_memalloc(size);
	if (!temp)
		return (NULL);
	ft_strcpy(temp, mem);
	free(mem);
	return (temp);
}

void	*ft_memrealloc(void *mem, size_t previous, size_t size)
{
	char *temp;

	temp = ft_memalloc(size);
	if (!temp)
		return (NULL);
	ft_memcpy(temp, mem, previous);
	free(mem);
	return (temp);
}
