/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:54:36 by afrangio          #+#    #+#             */
/*   Updated: 2017/11/22 18:48:42 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t	i;

	if (!(*needle))
		return ((char *)hay);
	while (*hay && len--)
	{
		if (*hay == needle[0])
		{
			i = 1;
			while (len-- && hay[i] && needle[i] && hay[i] == needle[i])
				++i;
			if (i == ft_strlen(needle))
				return ((char *)hay);
			len += i;
		}
		hay++;
	}
	return (NULL);
}
