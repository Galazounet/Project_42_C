/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:18:17 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/11 15:54:39 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	k = 0;
	i = 0;
	if (s)
	{
		j = ft_strlen(s);
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (s[i])
			while (s[j - 1] == ' ' || s[j - 1] == '\n' || s[j - 1] == '\t')
				j--;
		if (!(str = malloc(sizeof(char) * (j - i) + 1)))
			return (NULL);
		ft_strncpy(str, &s[i], (j - i));
		str[j - i] = '\0';
		return (str);
	}
	return (0);
}
