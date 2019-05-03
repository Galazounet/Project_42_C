/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 16:48:02 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/02 13:37:59 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURSE_H
# define CURSE_H

# define N_MENUSTR 7
# define SEEDSTR "Enter the desired seed (max 10 ch): "
# define TIMEOUTSTR "Enter the desired timeout (max 10 ch): "

# include <curse.h>
# include <string.h>
# include "../../libft/libft.h"
# include "../../libft/get_next_line.h"
# include <stdio.h>
# include <ncurses.h>
# include <dirent.h>
# include <locale.h>
# include <sys/ioctl.h>

typedef struct		s_choice_list
{
	int				selected;
	char			*(*choice)(void *);
	char			*name;
	char			*ret;
	char			*opt;
}					t_choice_list;

typedef struct		s_curses
{
	WINDOW			*screen;
	t_choice_list	list[N_MENUSTR];
}					t_curses;

char				*getmapfile(void *addr);
char				*getplone(void *addr);
char				*getpltwo(void *addr);
char				*gettimeout(void *addr);
char				*getseed(void *addr);
int					printmenu(t_curses c, int highlight);
int					printopt(t_curses c);
int					printfiles(char **files, int highlight);
int					print(char **files, int highlight, int size, int namesize);
int					initcurses(t_curses *c);
int					counttab(char **tab);
char				**getfiles(char *path);
int					count_files(char *path);
char				**form_arg(t_curses *c);
int					count_arg(t_choice_list *list);
void				delcurses(t_curses *c);
void				deltab(char **tab);
char				*die(void *addr);
char				*start(void *addr);

#endif
