/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 22:30:16 by afrangio          #+#    #+#             */
/*   Updated: 2017/11/22 18:48:43 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int	i;
	int	j;
	int temp;

	i = 0;
	if (needle[i] == '\0')
		return (char*)(haystack);
	while (haystack[i])
	{
		j = 0;
		temp = i;
		while (haystack[i] == needle[j])
		{
			i++;
			j++;
			if (!needle[j])
				return (char*)(&haystack[temp]);
		}
		i = temp;
		i++;
	}
	return (0);
}
