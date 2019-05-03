/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ld.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:20:20 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/27 23:11:53 by dygouasd         ###   ########.fr       */
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
		ft_putstr(" | LD | ");
		ft_putnbr(params[0]);
		ft_putstr(" in r");
		ft_putnbr(params[1]);
		ft_putstr("\nADV  ");
		ft_putnbr(adv);
		ft_putendl("");
	}
}

static void		print_adv(t_cv *env, unsigned adv)
{
	if (!env->graphical_interface && env->verbose)
	{
		ft_putstr("LD | ADV  ");
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
	setter[2] = set_dir_4;
	setter[3] = set_ind;
	pc = proc->reg[REG_PC] + 2;
	setter[ocp.param1](&param[0], env, proc, &pc);
	setter[ocp.param2](&param[1], env, proc, &pc);
	return ((pc - proc->reg[REG_PC]));
}

int				op_ld(t_cv *env, t_proc *proc)
{
	t_ocp		ocp;
	unsigned	param[2];
	unsigned	temp;

	temp = read_8(env, (proc->reg[REG_PC] + 1));
	ocp = *(t_ocp*)&temp;
	shift_ocp(&ocp, 2);
	temp = set_param(param, env, proc, ocp);
	if (ocp.param1 == REG_CODE || ocp.param2 != REG_CODE)
	{
		proc->reg[REG_PC] += temp;
		print_adv(env, temp);
		return (SUCCESS);
	}
	if (check_reg_range(param[1]))
	{
		proc->reg[param[1]] = param[0];
		proc->reg[REG_CF] = (proc->reg[param[1]] == 0) ? 1 : 0;
	}
	print_verbose(env, param, proc, temp);
	proc->reg[REG_PC] += temp;
	return (SUCCESS);
}
