/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 16:49:29 by dygouasd          #+#    #+#             */
/*   Updated: 2019/02/22 05:12:05 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static void	print_verbose(unsigned id, unsigned warrior)
{
	ft_putstr("P    ");
	ft_putnbr(id);
	ft_putstr(" | LIVE ");
	ft_putnbr((unsigned)warrior);
	ft_putstr("\nADV  ");
	ft_putnbr(5);
	ft_putstr("\n");
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

int			op_live(t_cv *env, t_proc *process)
{
	unsigned warrior;

	++(process->live);
	warrior = read_32(env, process->reg[REG_PC] + 1);
	if (check_id(env, warrior) >= 0)
	{
		env->vm.live_warrior = warrior;
		if (!env->graphical_interface)
		{
			ft_putstr("Le joueur ");
			ft_putnbr(warrior);
			ft_putstr(" (");
			ft_putstr((char *)env->warrior[check_id(env, warrior)].name);
			ft_putendl(") est en vie");
		}
	}
	else if (!env->graphical_interface && env->verbose)
		print_verbose(process->id, warrior);
	process->reg[REG_PC] += 5;
	return (SUCCESS);
}
