/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curs_getter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/02 12:59:11 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/02 12:59:12 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <curse.h>

char		*getmapfile(void *addr)
{
	char			**files;
	int				highlight;
	int				get;
	int				i;
	char			*ret;

	highlight = 0;
	if ((files = getfiles("../resources/maps/")) == NULL)
		return (NULL);
	i = counttab(files);
	get = 0;
	while (get != 10)
	{
		printfiles(files, highlight);
		get = getch();
		if (get == KEY_UP)
			highlight = highlight > 0 ? highlight - 1 : highlight;
		else if (get == KEY_DOWN)
			highlight = highlight < i - 1 ? highlight + 1 : highlight;
	}
	if ((ret = ft_strjoin("../resources/maps/", files[highlight])) == NULL)
		return (NULL);
	clear();
	deltab(files);
	return (ret);
}

char		*getplone(void *addr)
{
	char			**files;
	int				highlight;
	int				get;
	int				i;
	char			*ret;

	highlight = 0;
	if ((files = getfiles("../resources/players/")) == NULL)
		return (NULL);
	i = counttab(files);
	get = 0;
	while (get != 10)
	{
		printfiles(files, highlight);
		get = getch();
		if (get == KEY_UP)
			highlight = highlight > 0 ? highlight - 1 : highlight;
		else if (get == KEY_DOWN)
			highlight = highlight < i - 1 ? highlight + 1 : highlight;
	}
	if ((ret = ft_strjoin("../resources/players/", files[highlight])) == NULL)
		return (NULL);
	clear();
	deltab(files);
	return (ret);
}

char		*getpltwo(void *addr)
{
	char			**files;
	int				highlight;
	int				get;
	int				i;
	char			*ret;

	highlight = 0;
	if ((files = getfiles("../resources/players/")) == NULL)
		return (NULL);
	i = counttab(files);
	get = 0;
	while (get != 10)
	{
		printfiles(files, highlight);
		get = getch();
		if (get == KEY_UP)
			highlight = highlight > 0 ? highlight - 1 : highlight;
		else if (get == KEY_DOWN)
			highlight = highlight < i - 1 ? highlight + 1 : highlight;
	}
	if ((ret = ft_strjoin("../resources/players/", files[highlight])) == NULL)
		return (NULL);
	clear();
	deltab(files);
	return (ret);
}

char		*gettimeout(void *addr)
{
	char *ret;

	echo();
	curs_set(1);
	if ((ret = malloc(10)) == NULL)
		return (NULL);
	while (42)
	{
		mvprintw(LINES / 2, COLS / 2 - 36, TIMEOUTSTR);
		getnstr(ret, 10);
		if (ft_atoi(ret) != 0 && ft_atoi(ret) > 0)
			break ;
	}
	clear();
	noecho();
	curs_set(0);
	return (ret);
}

char		*getseed(void *addr)
{
	char *ret;

	echo();
	curs_set(1);
	if ((ret = malloc(10)) == NULL)
		return (NULL);
	while (42)
	{
		mvprintw(LINES / 2, COLS / 2 - 36, SEEDSTR);
		getnstr(ret, 10);
		if (ft_atoi(ret) != 0)
			break ;
	}
	clear();
	noecho();
	curs_set(0);
	return (ret);
}
