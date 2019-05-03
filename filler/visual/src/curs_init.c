/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curs_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:59:05 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/02 13:04:26 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curse.h>

int		initcurses(t_curses *c)
{
	ft_memset(c->list, 0, sizeof(t_choice_list) * 6);
	c->list[0].ret = ft_strdup("../resources/maps/map01");
	c->list[1].ret = ft_strdup("../dygouasd.filler");
	c->list[2].ret = ft_strdup("../resources/players/abanlin.filler");
	c->list[0].opt = "-f";
	c->list[1].opt = "-p1";
	c->list[2].opt = "-p2";
	c->list[3].opt = "-s";
	c->list[4].opt = "-t";
	c->list[0].name = "1: Choose a map";
	c->list[1].name = "2: Choose player 1";
	c->list[2].name = "3: Choose player 2";
	c->list[3].name = "4: Choose a seed";
	c->list[4].name = "5: Set timeout";
	c->list[5].name = "6: Let's do this !";
	c->list[6].name = "7: Well, i'm done. Bye.";
	c->list[0].selected = 1;
	c->list[0].choice = getmapfile;
	c->list[1].choice = getplone;
	c->list[2].choice = getpltwo;
	c->list[3].choice = getseed;
	c->list[4].choice = gettimeout;
	c->list[5].choice = start;
	c->list[6].choice = die;
	return (0);
}
