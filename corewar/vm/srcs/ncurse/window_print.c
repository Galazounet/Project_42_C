/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:41:40 by dygouasd          #+#    #+#             */
/*   Updated: 2019/02/27 22:47:50 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		create_window(void)
{
	int		x;
	int		y;

	x = 3;
	y = 1;
	attron(COLOR_PAIR(5));
	while (x++ < 243)
		mvprintw(y, x, " ");
	y--;
	while (y++ < 67)
		mvprintw(y, x, " ");
	x++;
	while (x-- > 3)
		mvprintw(y, x, " ");
	y++;
	x++;
	while (y-- > 1)
		mvprintw(y, x, " ");
	x = 199;
	while (y++ < 67)
		mvprintw(y, x, " ");
	y = 55;
	while (x++ < 243)
		mvprintw(y, x, " ");
	attroff(COLOR_PAIR(5));
}

static void	write_warriors_cara(t_cv env, int y, int x)
{
	int		i;
	int		live;
	char	name[30];

	i = 0;
	live = 0;
	while (++i <= (int)(env.nb_warriors))
	{
		y += 3;
		mvprintw(y, x, "Player -%i : ", i);
		attron(COLOR_PAIR(i));
		ft_strncpy(name, (char *)env.warrior[i - 1].name, 30);
		mvprintw(y, x + 12, "%s", name);
		attroff(COLOR_PAIR(i));
		live = nb_life(env.vm.queue, i - 1);
		y += 1;
		mvprintw(y, x, "Live in current period : %-10i", live);
	}
}

void		window_caracteristique(t_cv env, t_visur *cmd)
{
	int		x;
	int		y;

	x = 201;
	y = 3;
	if (cmd->running == 0)
		mvprintw(y, x, " ** PAUSE ** ");
	else
		mvprintw(y, x, "** RUNNING **");
	y += 4;
	mvprintw(y, x, "Nb Cycle : %i", env.vm.cycle - 1);
	y += 4;
	mvprintw(y, x, "Processes : %-10iCYCLE TO DIE : %-5i",
		count_processes(env.vm.queue), env.vm.ctd);
	y += 4;
	mvprintw(y, x, "CYCLE_DELTA : %-8iMAX_CHECK : %i", CYCLE_DELTA, MAX_CHECKS);
	y += 4;
	mvprintw(y, x, "NBR_LIVE : %i", NBR_LIVE);
	y += 4;
	mvprintw(y, x, "SPEED : %-5i~Cycle/s", count_speed(cmd->speed));
	write_warriors_cara(env, y, x);
}

void		write_winner(t_cv *env)
{
	int		i;
	char	name[30];

	i = 0;
	while (env->nb_warriors > i)
	{
		if (env->warrior[i].warrior_number == env->vm.live_warrior)
		{
			ft_strncpy(name, (char*)env->warrior[i].name, 30);
			attron(COLOR_PAIR(3));
			mvprintw(50, 201, "Player %i : %s", env->vm.live_warrior, \
						name);
			mvprintw(51, 214, "Won this Game");
			attroff(COLOR_PAIR(3));
			return ;
		}
		i++;
	}
	mvprintw(50, 220, "Nobody Win this game !");
}

void		print_command(void)
{
	int		x;
	int		y;

	x = 201;
	y = 59;
	attrset(COLOR_PAIR(0));
	mvprintw(y, x, "\'sp\' Start and Pause");
	mvprintw(y, x + 25, "\'d\' to go 1 by 1");
	y += 4;
	mvprintw(y, x, "\'q\' to go Faster");
	mvprintw(y, x + 25, "\'w\' to go Slower");
}
