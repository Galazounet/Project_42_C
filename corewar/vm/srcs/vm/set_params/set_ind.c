/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ind.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 04:33:01 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/22 06:14:48 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

int	set_lind(unsigned *param, t_cv *env, t_proc *proc, unsigned *pc)
{
	unsigned red;

	red = read_16(env, (*pc) % MEM_SIZE);
	(void)*proc;
	*param = read_32(env, red + proc->reg[REG_PC]);
	*pc += 2;
	return (SUCCESS);
}

int	set_ind(unsigned *param, t_cv *env, t_proc *proc, unsigned *pc)
{
	unsigned red;

	red = read_16(env, (*pc)) % IDX_MOD;
	(void)*proc;
	*param = read_32(env, red + proc->reg[REG_PC]);
	*pc += 2;
	return (SUCCESS);
}
