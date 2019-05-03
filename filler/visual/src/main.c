/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 12:28:24 by dygouasd          #+#    #+#             */
/*   Updated: 2018/03/02 13:00:55 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>
#include <curse.h>

void	do_filler(t_all *a)
{
	int			rot;
	int			ret;

	rot = 0;
	setrenders(a->i, a->w, a->t, a->r);
	while (!event(&a->i, a->m, a->w, a->r))
	{
		if (a->i.run == -1 || a->i.run == END)
			break ;
		if (a->i.run == 1)
			ret = getmap(&a->m, a->in);
		render_map(a);
		if (ret == 0)
		{
			SDL_RenderCopy(a->w.renderer, a->t.fondtransp, NULL, &a->r.fwin);
			SDL_RenderCopy(a->w.renderer, a->t.win, NULL, &a->r.winner);
		}
		render_progressbar(a);
		update(a);
		setrenders(a->i, a->w, a->t, a->r);
		++rot == 1 ? waitforstart(a) : ++rot;
		SDL_Delay(a->i.speed * 10);
	}
	SDL_RenderCopy(a->w.renderer, a->t.stoprbutton, NULL, &a->r.stopbutt);
	update(a);
}

char	*start(void *addr)
{
	char		**argv;
	t_all		a;
	t_curses	*c;
	int			filler_vm;

	c = (t_curses *)addr;
	argv = form_arg(c);
	if (init_sdl(&a) == -1)
		return (NULL);
	while (a.i.run != END)
	{
		if ((filler_vm = init_render(&a, argv, NULL)) == -1)
			return (NULL);
		do_filler(&a);
		free_all(&a);
		free_sdl(&a);
		kill(filler_vm, SIGKILL);
	}
	deltab(argv);
	delcurses(c);
	return (NULL);
}

char	*die(void *addr)
{
	(void)addr;
	return (NULL);
}

void	timetoplay(t_curses c)
{
	static int	highlight;
	int			get;

	while (42)
	{
		printopt(c);
		printmenu(c, highlight);
		get = getch();
		if (get == KEY_UP || get == KEY_LEFT)
			highlight = highlight > 0 ? highlight - 1 : N_MENUSTR - 1;
		else if (get == KEY_DOWN || get == KEY_RIGHT)
			highlight = highlight < N_MENUSTR - 1 ? highlight + 1 : 0;
		else if (get <= '7' && get >= '1')
			highlight = get - 49;
		else if (get == 'q')
			return ;
		else if (get == 10)
		{
			wclear(c.screen);
			wrefresh(c.screen);
			if ((c.list[highlight].ret = c.list[highlight].choice(&c)) == NULL)
				return ;
		}
		c.list[highlight].selected = 1;
	}
}

int		main(int argc, char **argv, char **env)
{
	t_curses		c;
	unsigned int	color;

	signal(SIGWINCH, signal_handler);
	initscr();
	start_color();
	color = init_color(color, 100, 100, 100);
	assume_default_colors(COLOR_GREEN, color);
	noecho();
	cbreak();
	keypad(stdscr, TRUE);
	curs_set(0);
	c.screen = subwin(stdscr, 15, 30, LINES / 2 - 4, COLS / 2 - 14);
	box(c.screen, ACS_VLINE, ACS_HLINE);
	initcurses(&c);
	timetoplay(c);
	endwin();
	return (EXIT_FAILURE);
}
