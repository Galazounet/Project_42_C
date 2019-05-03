/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:14:31 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/28 01:57:38 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static void		print_verbose(t_cv *env, unsigned *params, unsigned p,
								unsigned adv)
{
	if (!env->graphical_interface && env->verbose)
	{
		ft_putstr("P    ");
		ft_putnbr(p);
		ft_putstr(" | SUB | ");
		ft_putnbr(params[0]);
		ft_putstr(" - ");
		ft_putnbr(params[1]);
		ft_putstr(" in ");
		ft_putstr("r");
		ft_putnbr(params[2]);
		ft_putstr("\nADV  ");
		ft_putnbr(adv);
		ft_putendl("");
	}
}

static void		print_adv(t_cv *env, unsigned adv)
{
	if (!env->graphical_interface && env->verbose)
	{
		ft_putstr("SUB | ADV  ");
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
	setter[2] = set_dir_4;
	setter[3] = set_ind;
	pc = proc->reg[REG_PC] + 2;
	setter[ocp.param1](&param[0], env, proc, &pc);
	setter[ocp.param2](&param[1], env, proc, &pc);
	setter[1] = set_reg_number;
	setter[ocp.param3](&param[2], env, proc, &pc);
	return ((pc - proc->reg[REG_PC]));
}

int				op_sub(t_cv *env, t_proc *proc)
{
	t_ocp		ocp;
	unsigned	param[3];
	unsigned	temp;

	temp = read_8(env, (proc->reg[REG_PC] + 1));
	ocp = *(t_ocp*)&temp;
	shift_ocp(&ocp, 3);
	temp = set_param(param, env, proc, ocp);
	if (ocp.param1 != REG_CODE || ocp.param2 != REG_CODE
		|| ocp.param3 != REG_CODE)
	{
		proc->reg[REG_PC] += temp;
		print_adv(env, temp);
		return (SUCCESS);
	}
	if (check_reg_range(param[2]))
	{
		proc->reg[param[2]] = param[0] - param[1];
		proc->reg[REG_CF] = (proc->reg[param[2]] == 0) ? 1 : 0;
	}
	print_verbose(env, param, proc->id, temp);
	proc->reg[REG_PC] += temp;
	return (SUCCESS);
}
