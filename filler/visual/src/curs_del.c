/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curs_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:59:15 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/02 12:59:16 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curse.h>

void		delcurses(t_curses *c)
{
	int		i;

	i = 0;
	delwin(c->screen);
	while (i < N_MENUSTR)
	{
		if (c->list[i].ret != NULL)
			free(c->list[i].ret);
		++i;
	}
}

void		deltab(char **tab)
{
	int		i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i] != NULL)
	{
		free(tab[i]);
		++i;
	}
	free(tab);
}
