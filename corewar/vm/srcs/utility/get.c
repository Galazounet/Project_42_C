/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:45:28 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/22 06:43:52 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

t_op		*get_op(void)
{
	static t_op op[17];

	op[1] = op_live;
	op[2] = op_ld;
	op[3] = op_st;
	op[4] = op_add;
	op[5] = op_sub;
	op[6] = op_and;
	op[7] = op_or;
	op[8] = op_xor;
	op[9] = op_zjmp;
	op[10] = op_ldi;
	op[11] = op_sti;
	op[12] = op_fork;
	op[13] = op_lld;
	op[14] = op_lldi;
	op[15] = op_lfork;
	op[16] = op_aff;
	return (op);
}

unsigned	*get_cost(void)
{
	static unsigned	cost[17];

	cost[1] = 10;
	cost[2] = 5;
	cost[3] = 5;
	cost[4] = 10;
	cost[5] = 10;
	cost[6] = 6;
	cost[7] = 6;
	cost[8] = 6;
	cost[9] = 20;
	cost[10] = 25;
	cost[11] = 25;
	cost[12] = 800;
	cost[13] = 10;
	cost[14] = 50;
	cost[15] = 1000;
	cost[16] = 2;
	return (cost);
}

unsigned	get_proc_count(t_vm vm)
{
	unsigned	i;
	t_proc		*tmp;

	i = 0;
	tmp = vm.queue;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
