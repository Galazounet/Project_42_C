/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string_pars.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:30:37 by suddin            #+#    #+#             */
/*   Updated: 2018/10/06 00:34:46 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char	*get_string_pars(char **tab, t_lexobj *start, t_lexobj *end)
{
	int		i;
	int		beg;
	char	*ret;

	if (!tab || !start || !end || start->type != ASM_STRING_START\
			|| end->type != ASM_STRING_END)
		return (NULL);
	if (start->line == end->line && start->start_index < end->start_index)
		return (ft_strdupn(&(tab[start->line][start->start_index + 1]),\
					end->start_index));
		i = start->line;
	beg = start->start_index + 1;
	ret = NULL;
	if (end->line > start->line)
	{
		while (i < end->line)
		{
			string_join(&ret, &(tab[i][beg]), ft_strlen(&(tab[i][beg])));
			string_join(&ret, "\n", 1);
			beg = 0;
			i++;
		}
		string_join(&ret, &(tab[i][beg]), tab[i][end->start_index]);
	}
	return (ret);
}
