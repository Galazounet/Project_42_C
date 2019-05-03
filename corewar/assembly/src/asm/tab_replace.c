/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:34:38 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:00:06 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline void	ft_replace(char *str, int chr, int rep)
{
	int i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		if (str[i] == chr)
			str[i] = rep;
		i++;
	}
}

void				tab_replace(char **tab, int chr, int rep)
{
	int i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
		ft_replace(tab[i++], chr, rep);
}
