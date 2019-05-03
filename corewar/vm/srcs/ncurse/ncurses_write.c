/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_write.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 21:03:50 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/26 21:44:49 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		ncurses_init(void)
{
	initscr();
	noecho();
	nodelay(stdscr, TRUE);
	start_color();
	create_window();
	curs_set(0);
	init_color(COLOR_BLUE, 500, 500, 500);
	init_color(COLOR_WHITE, 1000, 1000, 1000);
	init_pair(0, COLOR_WHITE, COLOR_BLACK);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_CYAN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_BLUE);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	init_pair(10, COLOR_BLACK, COLOR_BLUE);
	init_pair(20, COLOR_BLACK, COLOR_GREEN);
	init_pair(30, COLOR_BLACK, COLOR_CYAN);
	init_pair(40, COLOR_BLACK, COLOR_RED);
	init_pair(50, COLOR_BLACK, COLOR_YELLOW);
}

void		modif_speed(t_visur *cmd)
{
	if (cmd->key == 32 && cmd->running == 0)
		cmd->running = 1;
	else if (cmd->key == 32 && cmd->running == 1)
		cmd->running = 0;
	else if ((cmd->key == 'q' || cmd->key == 'Q') && cmd->speed > 0)
		cmd->speed -= 2000;
	else if ((cmd->key == 'w' || cmd->key == 'W') && cmd->speed < 200000)
		cmd->speed += 2000;
}

static void	command_ncurse(t_visur *cmd, t_cv *env)
{
	if (cmd->running == 1)
	{
		cmd->key = getch();
		modif_speed(cmd);
		attrset(COLOR_PAIR(0));
		window_caracteristique(*env, cmd);
		refresh();
	}
	while (cmd->running != 1)
	{
		cmd->key = getch();
		if (cmd->key == 'd')
			break ;
		modif_speed(cmd);
		attrset(COLOR_PAIR(0));
		window_caracteristique(*env, cmd);
		refresh();
	}
}

void		ncurses_writevm(t_vm *vm, t_cv *env)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0 && i != 0)
		{
			++(env->visu.y_win);
			env->visu.x_win = 6;
		}
		attron(COLOR_PAIR((vm->parent[i])));
		if (vm->index[i] == 1)
			attron(COLOR_PAIR((vm->parent[i] + 1) * 10));
		mvprintw(env->visu.y_win, env->visu.x_win, "%.2x", vm->memory[i]);
		env->visu.x_win += 2;
		attroff(COLOR_PAIR((vm->parent[i])));
		if ((i++ + 1) % 64 != 0)
		{
			attron(COLOR_PAIR(6));
			mvprintw(env->visu.y_win, env->visu.x_win, "%c", ' ');
			env->visu.x_win += 1;
		}
		attrset(COLOR_PAIR(6));
	}
}

void		ncurses_dump(t_vm *vm, t_cv env, t_visur *cmd)
{
	env.visu.j = 0;
	env.visu.w_nb = 0;
	env.visu.x_win = 6;
	env.visu.y_win = 3;
	ft_bzero(vm->index, sizeof(vm->index));
	set_index(vm);
	ncurses_init();
	window_caracteristique(env, cmd);
	ncurses_writevm(vm, &env);
	print_command();
	command_ncurse(cmd, &env);
	if (cmd->key != 'd')
		usleep(cmd->speed);
	refresh();
}
