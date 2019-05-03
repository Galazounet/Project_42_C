/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:15:33 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/11 10:40:14 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*result;

	i = 0;
	if (s)
	{
		if (!(result = malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		while (s[i] != '\0')
		{
			result[i] = f(i, s[i]);
			i++;
		}
		result[i] = '\0';
		return (result);
	}
	return (NULL);
}
