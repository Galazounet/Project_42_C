/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sti.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:21:18 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/27 23:12:30 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static void		print_verbose(t_cv *env, unsigned *params, unsigned p,
								int add)
{
	if (!env->graphical_interface && env->verbose)
	{
		ft_putstr("P    ");
		ft_putnbr(p);
		ft_putstr(" | STI | ");
		ft_putnbr((int)params[0]);
		ft_putstr(" in ");
		ft_putnbr(params[1]);
		ft_putstr(" + ");
		ft_putnbr((int)params[2]);
		ft_putstr(" (with pc and mod ");
		ft_putnbr((int16_t)add);
		ft_putstr(")");
	}
}

static void		print__adv(t_cv *env, unsigned adv)
{
	if (!env->graphical_interface && env->verbose)
	{
		ft_putstr("\nADV  ");
		ft_putnbr(adv);
		ft_putendl("");
	}
}

static void		print_adv(t_cv *env, unsigned adv)
{
	if (!env->graphical_interface && env->verbose)
	{
		ft_putstr("STI | ADV  ");
		ft_putnbr(adv);
		ft_putendl("");
	}
}

static unsigned	set_param(unsigned *param, t_cv *env, t_proc *proc,
							t_ocp ocp)
{
	unsigned	pc;
	t_setlist	setter[4];

	setter[0] = nothing;
	setter[1] = set_reg_value;
	setter[2] = set_dir_2;
	setter[3] = set_ind;
	pc = proc->reg[REG_PC] + 2;
	setter[ocp.param1](&param[0], env, proc, &pc);
	setter[ocp.param2](&param[1], env, proc, &pc);
	setter[ocp.param3](&param[2], env, proc, &pc);
	return ((pc - proc->reg[REG_PC]));
}

int				op_sti(t_cv *env, t_proc *proc)
{
	t_ocp		ocp;
	unsigned	param[3];
	unsigned	temp;
	int			dd;

	temp = read_8(env, (proc->reg[REG_PC] + 1));
	ocp = *(t_ocp*)&temp;
	shift_ocp(&ocp, 3);
	temp = set_param(param, env, proc, ocp);
	if (ocp.param1 != REG_CODE || ocp.param3 == IND_CODE)
	{
		proc->reg[REG_PC] += temp;
		print_adv(env, temp);
		return (SUCCESS);
	}
	dd = (int)((short)param[1] + (short)param[2]);
	dd = dd % IDX_MOD;
	dd += proc->reg[REG_PC];
	if (dd < 0)
		dd = MEM_SIZE + dd;
	write_32(env, (unsigned)dd, param[0], (int)proc->parent);
	print_verbose(env, param, proc->id, dd);
	print__adv(env, temp);
	proc->reg[REG_PC] += temp;
	return (SUCCESS);
}
