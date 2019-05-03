/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 04:32:11 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/20 19:40:35 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

int	set_dir_2(unsigned *param, t_cv *env, t_proc *proc, unsigned *pc)
{
	(void)*proc;
	*param = read_16(env, (*pc) % MEM_SIZE);
	*pc += 2;
	return (SUCCESS);
}

int	set_dir_4(unsigned *param, t_cv *env, t_proc *proc, unsigned *pc)
{
	(void)*proc;
	*param = read_32(env, (*pc) % MEM_SIZE);
	*pc += 4;
	return (SUCCESS);
}
