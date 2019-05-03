/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:37:11 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/27 23:09:20 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static int	exec_instru(t_cv *env, t_proc *proc, int opcode)
{
	t_op		*op;
	unsigned	*cost;

	op = get_op();
	cost = get_cost();
	if ((opcode < 1 || opcode > 16) && proc->op == 0)
		return (-1);
	else
	{
		if (proc->wait <= 0)
		{
			proc->wait = (signed)cost[opcode] - 1;
			proc->op = opcode;
		}
		else
			--(proc->wait);
		if (proc->wait == 0)
		{
			op[proc->op](env, proc);
			proc->op = 0;
		}
	}
	return (0);
}

static int	process_check(t_cv *env)
{
	t_proc	*tmp;
	int		opcode;

	tmp = env->vm.queue;
	while (tmp)
	{
		opcode = read_8(env, tmp->reg[REG_PC]);
		if (exec_instru(env, tmp, opcode) != 0)
			++(tmp->reg[REG_PC]);
		tmp = tmp->next;
	}
	return (SUCCESS);
}

static int	start(t_cv *env, t_visur *cmd)
{
	while (env->vm.queue)
	{
		print_cycle(env);
		if (env->graphical_interface
			&& (env->vm.cycle >= env->graphical_interface))
			ncurses_dump(&(env->vm), *env, cmd);
		if (is_cycle_to_die(&(env->vm)))
		{
			kill_not_alive(&(env->vm.queue));
			print_ctd(env);
		}
		process_check(env);
		++(env->vm.cycle);
		if ((env->dump >= 0 && env->vm.cycle == (unsigned)env->dump + 1)
			|| env->dump == 0)
		{
			env->dump = 0;
			dump(env);
			return (SUCCESS);
		}
	}
	if (env->dump > 0)
		dump(env);
	return (SUCCESS);
}

static int	check_id(t_cv *env, unsigned id)
{
	int i;

	i = 0;
	while (i < env->nb_warriors)
	{
		if (env->warrior[i].warrior_number == id)
			return (i);
		++i;
	}
	return (-1);
}

int			run(t_cv *env)
{
	int		ret;
	t_visur	cmd;

	cmd.speed = 200000;
	cmd.running = 0;
	ret = start(env, &cmd);
	if (ret != 0)
		return (ret);
	if (!env->graphical_interface && env->dump < 0)
	{
		if (env->vm.live_warrior)
		{
			ft_putstr("Le joueur ");
			ft_putnbr(env->vm.live_warrior);
			ft_putstr(" (");
			ft_putstr((char *)env->warrior[check_id(env,
						env->vm.live_warrior)].name);
			ft_putendl(") à gagné.");
		}
		else
			ft_putendl("Aucun joueur n'a gagné");
	}
	else
		print_end(env);
	return (SUCCESS);
}
