/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   st.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:21:12 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/27 23:12:26 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static void		print_verbose(t_cv *env, unsigned *params, t_proc *p,
								unsigned adv)
{
	if (!env->graphical_interface && env->verbose)
	{
		ft_putstr("P    ");
		ft_putnbr(p->id);
		ft_putstr(" | ST | r");
		ft_putnbr(params[0]);
		ft_putstr("(");
		ft_putnbr(p->reg[params[0]]);
		ft_putstr(")");
		ft_putstr(" in ");
		ft_putnbr((short)params[1]);
		ft_putstr("\nADV  ");
		ft_putnbr(adv);
		ft_putendl("");
	}
}

static void		print_adv(t_cv *env, unsigned adv)
{
	if (!env->graphical_interface && env->verbose)
	{
		ft_putstr("ST | ADV  ");
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
	setter[1] = set_reg_number;
	setter[2] = set_dir_2;
	setter[3] = set_dir_2;
	pc = proc->reg[REG_PC] + 2;
	setter[ocp.param1](&param[0], env, proc, &pc);
	setter[ocp.param2](&param[1], env, proc, &pc);
	return ((pc - proc->reg[REG_PC]));
}

int				op_st(t_cv *env, t_proc *proc)
{
	t_ocp		ocp;
	unsigned	param[3];
	unsigned	temp;

	temp = read_8(env, (proc->reg[REG_PC] + 1));
	ocp = *(t_ocp*)&temp;
	shift_ocp(&ocp, 2);
	if ((temp = set_param(param, env, proc, ocp)) == -1u
		|| ocp.param1 != REG_CODE || ocp.param2 == DIR_CODE)
	{
		proc->reg[REG_PC] += temp;
		print_adv(env, temp);
		return (SUCCESS);
	}
	if (ocp.param2 == REG_CODE && check_reg_range(param[1]))
		proc->reg[param[1]] = proc->reg[param[0]];
	else if (ocp.param2 == IND_CODE)
		write_32(env, (proc->reg[REG_PC] + (short)param[1] % IDX_MOD),
					proc->reg[param[0]], (int)proc->parent);
	print_verbose(env, param, proc, temp);
	proc->reg[REG_PC] += temp;
	return (SUCCESS);
}
