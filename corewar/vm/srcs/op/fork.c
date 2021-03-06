/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:19:57 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/27 19:24:22 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static void	print_verbose(t_cv *env, int params, t_proc *p,
								unsigned adv)
{
	if (!env->graphical_interface && env->verbose)
	{
		ft_putstr("P    ");
		ft_putnbr(p->id);
		ft_putstr(" | FORK | ");
		ft_putnbr((short)params);
		ft_putstr(" (");
		ft_putnbr(((short)(p->reg[REG_PC]) + (short)params));
		ft_putstr(")");
		ft_putstr("\nADV  ");
		ft_putnbr(adv);
		ft_putendl("");
	}
}

static void	copy(t_cv *env, t_proc *proc)
{
	ft_memcpy(env->vm.queue, proc, sizeof(t_proc) - sizeof(t_proc*));
	env->vm.queue->id = env->vm.process_tc;
	env->vm.process_tc += 1;
}

int			op_fork(t_cv *env, t_proc *proc)
{
	int		param;

	param = read_16(env, (proc->reg[REG_PC] + 1));
	push_process(&(env->vm.queue));
	copy(env, proc);
	env->vm.queue->reg[REG_PC] += ((int16_t)param % IDX_MOD);
	env->vm.queue->op = 0;
	if ((int)env->vm.queue->reg[REG_PC] < 0)
		env->vm.queue->reg[REG_PC] = MEM_SIZE + env->vm.queue->reg[REG_PC];
	print_verbose(env, param, proc, 3);
	proc->reg[REG_PC] += 3;
	return (SUCCESS);
}
