/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 19:29:36 by dygouasd          #+#    #+#             */
/*   Updated: 2017/11/11 12:44:44 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static int		count_words(char const *s, char c)
{
	int		i;
	int		j;
	int		k;

	j = 0;
	i = 0;
	k = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			j = 1;
		if (s[i] != c && j != 2)
		{
			k++;
			j = 2;
		}
		i++;
	}
	return (k);
}

static int		ft_len(char const *s, char c)
{
	int		i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	char	**str;
	int		j;

	j = 0;
	if (s)
	{
		i = count_words(s, c);
		if (!((str = malloc(sizeof(char*) * i + 1))))
			return (0);
		while (i > j)
		{
			while (*s == c && *s != '\0')
				s++;
			if (!(str[j] = ft_strsub(s, 0, ft_len(s, c))))
				return (NULL);
			s = &s[ft_len(s, c)];
			j++;
		}
		str[j] = NULL;
		return (str);
	}
	return (0);
}
