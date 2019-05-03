/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:58:43 by afrangio          #+#    #+#             */
/*   Updated: 2017/11/22 18:48:44 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	dst = ft_memalloc(len + 1);
	if (dst)
	{
		while (s[start] && i < len)
		{
			dst[i] = s[start];
			start++;
			i++;
		}
		dst[i] = '\0';
		return (dst);
	}
	return (NULL);
}
