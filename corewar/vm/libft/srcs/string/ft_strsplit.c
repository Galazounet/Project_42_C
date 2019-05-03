/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 22:35:32 by afrangio          #+#    #+#             */
/*   Updated: 2017/11/22 18:48:43 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(char const *s, char c)
{
	int			i;
	int			len;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			len++;
		i++;
	}
	return (len);
}

static void		ft_sublen(char const *s, char c, char **tab, int nbl)
{
	int			i;
	int			j;
	size_t		start;
	size_t		len;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c && nbl > 0)
		{
			nbl--;
			start = i;
			len = 0;
			while (s[i] != c && s[i] != '\0')
			{
				len++;
				i++;
			}
			tab[j++] = ft_strsub(s, start, len);
		}
		i++;
	}
	tab[j] = NULL;
}

char			**ft_strsplit(char const *s, char c)
{
	int			nbl;
	char		**tab;

	if (!s)
		return (NULL);
	nbl = ft_count(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (nbl + 1))))
		return (NULL);
	ft_sublen(s, c, tab, nbl);
	return (tab);
}
