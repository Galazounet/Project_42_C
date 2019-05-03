/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_reg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 04:31:43 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/20 19:40:55 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

int	set_reg_value(unsigned *param, t_cv *env, t_proc *proc, unsigned *pc)
{
	*param = read_8(env, (*pc) % MEM_SIZE);
	if (*param >= 1 && *param <= 16)
		*param = proc->reg[*param];
	else
		*param = 0;
	++(*pc);
	return (SUCCESS);
}

int	set_reg_number(unsigned *param, t_cv *env, t_proc *proc, unsigned *pc)
{
	(void)*proc;
	*param = read_8(env, (*pc) % MEM_SIZE);
	++(*pc);
	return (SUCCESS);
}
