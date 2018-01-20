/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:47:47 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/11 10:40:38 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!(needle[0]))
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] &&
					needle[j] != '\0' && (i + j) < len)
				j++;
			if (j == ft_strlen(needle))
				return ((char*)haystack + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
