/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ncurses_uti.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dygouasd <dygouasd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 18:37:32 by dygouasd          #+#    #+#             */
/*   Updated: 2019/02/26 20:07:07 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int		count_processes(t_proc *queue)
{
	t_proc	*count;
	int		nb;

	nb = 0;
	count = queue;
	while (count)
	{
		nb++;
		count = count->next;
	}
	return (nb);
}

void	print_end(t_cv *env)
{
	write_winner(env);
	mvprintw(53, 209, "Press any Key to finish");
	nodelay(stdscr, FALSE);
	if (env->graphical_interface)
		getch();
	endwin();
}

int		nb_life(t_proc *queue, int i)
{
	t_proc	*count;
	int		nb;

	nb = 0;
	count = queue;
	while (count)
	{
		if (count->parent == (uint32_t)i)
			nb = nb + (int)(count->live);
		count = count->next;
	}
	return (nb);
}

void	set_index(t_vm *vm)
{
	t_proc *tmp;

	tmp = vm->queue;
	while (tmp)
	{
		vm->index[tmp->reg[REG_PC] % MEM_SIZE] = 1;
		tmp = tmp->next;
	}
}

int		count_speed(unsigned int speed)
{
	unsigned int	i;

	i = 200000;
	if (speed > 0 && speed <= 200000)
		return (speed == 200000 ? 1 : ((i - speed) / 2) / 100);
	else
		return (1000);
}
