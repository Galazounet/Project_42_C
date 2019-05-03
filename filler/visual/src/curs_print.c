/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curs_print.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:58:50 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/02 12:58:51 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curse.h>

int		printopt(t_curses c)
{
	mvprintw(2, 2, "~ Map: ");
	if (c.list[0].ret != NULL && ft_strrchr(c.list[0].ret, '/') != NULL)
		printw(ft_strrchr(c.list[0].ret, '/') + 1);
	mvprintw(3, 2, "~ Player 1: ");
	if (c.list[1].ret != NULL && ft_strrchr(c.list[1].ret, '/') != NULL)
		printw(ft_strrchr(c.list[1].ret, '/') + 1);
	mvprintw(4, 2, "~ Player 2: ");
	if (c.list[2].ret != NULL && ft_strrchr(c.list[2].ret, '/') != NULL)
		printw(ft_strrchr(c.list[2].ret, '/') + 1);
	mvprintw(5, 2, "~ Seed: ");
	if (c.list[3].ret != NULL)
		printw(c.list[3].ret);
	else
		printw("DEFAULT");
	mvprintw(6, 2, "~ Timeout: ");
	if (c.list[4].ret != NULL)
		printw(c.list[4].ret);
	else
		printw("DEFAULT");
	return (0);
}

int		printmenu(t_curses c, int highlight)
{
	int	i;

	i = 0;
	while (i < N_MENUSTR)
	{
		if (c.list[i].selected == 1 && highlight == i)
			attron(A_REVERSE | A_BOLD);
		else
			c.list[i].selected = 0;
		mvprintw(LINES / 2 - 3 + i * 2, COLS / 2 - 14 + 2, c.list[i].name);
		if (c.list[i].selected == 1)
			attroff(A_REVERSE | A_BOLD);
		++i;
	}
	return (0);
}

int		print(char **files, int highlight, int size, int namesize)
{
	int		i;

	i = 0;
	while (files[i] != NULL)
	{
		if (i == highlight)
			attron(A_REVERSE | A_BOLD);
		mvprintw(LINES / 2 - size / 2 - 1 + i * 2,
			COLS / 2 - namesize / 2 + 3, files[i]);
		if (i == highlight)
			attroff(A_REVERSE | A_BOLD);
		++i;
	}
	return (0);
}

int		printfiles(char **files, int highlight)
{
	int		size;
	int		namesize;

	WINDOW * screen;
	size = 0;
	namesize = 0;
	while (files[size] != NULL)
	{
		if (ft_strlen(files[size]) > namesize)
			namesize = ft_strlen(files[size]);
		size++;
	}
	screen = subwin(stdscr, size * 2 + 1, namesize + 5,
		LINES / 2 - size / 2 - 2, COLS / 2 - namesize / 2);
	box(screen, ACS_VLINE, ACS_HLINE);
	wrefresh(screen);
	print(files, highlight, size, namesize);
	delwin(screen);
	return (0);
}
