/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zjmp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:21:44 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/27 22:44:17 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static void	print_verbose_failed(t_cv *env, unsigned id, unsigned tmp)
{
	if (!env->graphical_interface && env->verbose)
	{
		ft_putstr("P    ");
		ft_putnbr(id);
		ft_putstr(" | ZJMP | ");
		ft_putnbr((short)tmp);
		ft_putendl(" FAILED");
		ft_putstr("ADV  ");
		ft_putnbr(3);
		ft_putendl("");
	}
}

static void	print_verbose_ok(t_cv *env, unsigned id, unsigned tmp)
{
	if (!env->graphical_interface && env->verbose)
	{
		ft_putstr("P    ");
		ft_putnbr(id);
		ft_putstr(" | ZJMP | ");
		ft_putnbr((short)tmp);
		ft_putendl(" OK");
	}
}

int			op_zjmp(t_cv *env, t_proc *proc)
{
	unsigned tmp;

	tmp = read_16(env, proc->reg[REG_PC] + 1);
	if (proc->reg[REG_CF])
	{
		proc->reg[REG_PC] += (tmp);
		print_verbose_ok(env, proc->id, tmp);
	}
	else
	{
		print_verbose_failed(env, proc->id, tmp);
		proc->reg[REG_PC] += 3;
	}
	return (SUCCESS);
}
