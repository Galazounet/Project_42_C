/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initiate_proc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 13:28:56 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/27 19:24:46 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

int		initiate_proc(t_cv *env)
{
	unsigned i;

	i = 0;
	env->vm.ctd = 1536;
	env->vm.cycle = 1;
	while (i < env->nb_warriors)
	{
		push_process(&(env->vm.queue));
		ft_bzero(env->vm.queue->reg, REG_SIZE);
		env->vm.queue->reg[REG_PC] = env->warrior[i].initial_pc;
		env->vm.queue->parent = (uint8_t)i;
		env->vm.queue->id = i;
		env->vm.queue->reg[1] = env->warrior[i].warrior_number;
		env->vm.queue->live = 0;
		env->vm.queue->wait = -1;
		env->vm.queue->op = 0;
		++i;
	}
	env->vm.process_tc = i;
	return (SUCCESS);
}
