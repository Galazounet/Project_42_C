/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 00:44:43 by suddin            #+#    #+#             */
/*   Updated: 2018/08/17 00:45:59 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline int	count_oc(char *str, int c)
{
	int i;
	int oc;

	if (!str)
		return (0);
	i = 0;
	oc = 0;
	while (str[i])
	{
		if (str[i] == c)
			oc++;
		i++;
	}
	return (oc);
}

static inline void	fill_tab(char **tab, char *str, int oc, int c)
{
	int i;
	int j;
	int n_oc;
	int str_len;

	if (!tab || !str)
		return ;
	i = 0;
	j = 0;
	str_len = ft_strlen(str);
	while (j < str_len && i < oc)
	{
		n_oc = (int)(ft_strchr(&(str[j]), c) - &(str[j]));
		tab[i] = ft_strdupn(&(str[j]), n_oc + 1);
		j += n_oc + 1;
		i++;
	}
	if (j < str_len)
		tab[i] = ft_strdup(&(str[j]));
}

char				**ft_strsplitn(char const *s, char c)
{
	char	**tab;
	int		oc;
	int		i;

	if (!s || (oc = count_oc((char *)s, c)) == 0)
		return (NULL);
	i = 0;
	if (!(tab = (char **)malloc((oc + 3) * sizeof(char *))))
		return (NULL);
	while (i < oc + 3)
	{
		tab[i] = NULL;
		i++;
	}
	fill_tab(tab, (char *)s, oc, c);
	return (tab);
}
