/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:19:00 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/27 23:11:37 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static void		print_verbose(t_cv *env)
{
	if (env->verbose)
	{
		ft_putstr("ADV  ");
		ft_putnbr(3);
		ft_putstr("\n");
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
	return ((pc - proc->reg[REG_PC]));
}

int				op_aff(t_cv *env, t_proc *proc)
{
	t_ocp		ocp;
	unsigned	param[2];
	unsigned	temp;

	temp = read_8(env, (proc->reg[REG_PC] + 1));
	ocp = *(t_ocp*)&temp;
	shift_ocp(&ocp, 3);
	if (ocp.param1 != REG_CODE)
	{
		proc->reg[REG_PC] += temp;
		return (SUCCESS);
	}
	temp = set_param(param, env, proc, ocp);
	if (check_reg_range(param[0]) && !env->graphical_interface)
	{
		ft_putstr("P    ");
		ft_putnbr(proc->id);
		ft_putstr(" | AFF: '");
		ft_putchar((char)(proc->reg[param[0]] % 256));
		ft_putendl("'");
		print_verbose(env);
	}
	proc->reg[REG_PC] += 3;
	return (SUCCESS);
}
