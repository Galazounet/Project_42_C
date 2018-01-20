/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 09:51:08 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/11 10:40:52 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (!(needle[0]))
		return ((char*)haystack);
	while (haystack[i] != '\0')
	{
		if (haystack[i] == needle[j])
		{
			while (haystack[i + j] == needle[j] && needle[j] != '\0')
				j++;
			if (j == ft_strlen(needle))
				return ((char*)haystack + i);
		}
		j = 0;
		i++;
	}
	return (NULL);
}
