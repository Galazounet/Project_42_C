/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 21:51:31 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/27 23:15:04 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

static int		check_nbrlive(t_vm *vm)
{
	t_proc	*tmp;
	int		count;

	count = 0;
	tmp = vm->queue;
	while (tmp)
	{
		count += tmp->live;
		if (count >= 21)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int				is_cycle_to_die(t_vm *vm)
{
	if (vm->ctd < 0)
		return (1);
	if (vm->cycle == vm->last_check)
	{
		++vm->check_count;
		return (1);
	}
	if ((signed)vm->cycle == ((signed)vm->last_check + vm->ctd))
	{
		++vm->check_count;
		vm->last_check = vm->cycle;
		if (check_nbrlive(vm) || vm->check_count == 10)
		{
			vm->check_count = 0;
			vm->ctd -= CYCLE_DELTA;
		}
		return (1);
	}
	return (0);
}

void			kill_not_alive(t_proc **queue)
{
	t_proc		*tmp;
	unsigned	*kill_list;
	unsigned	i;
	unsigned	j;

	if (!(kill_list = ft_memalloc(sizeof(unsigned) * 256)))
		return ;
	tmp = *queue;
	i = 0;
	while (tmp)
	{
		if (i > 255)
			if (!(kill_list = realloc(kill_list, sizeof(unsigned) * (i * 2))))
				return ;
		if (!tmp->live)
			kill_list[i++] = tmp->id;
		else
			tmp->live = 0;
		tmp = tmp->next;
	}
	j = -1u;
	while (++j < i)
		kill_process(queue, kill_list[j]);
	free(kill_list);
	kill_list = NULL;
}

int				check_reg_range(unsigned param)
{
	if (param >= 1 && param <= REG_NUMBER)
		return (1);
	else
		return (0);
}

void			shift_ocp(t_ocp *ocp, unsigned n_param)
{
	if (ocp->param1 == 0 && ocp->param2)
	{
		ocp->param1 = ocp->param2;
		ocp->param2 = 0;
	}
	if (n_param == 2)
		return ;
	if (ocp->param2 == 0 && ocp->param3)
	{
		ocp->param2 = ocp->param3;
		ocp->param3 = 0;
	}
	if (ocp->param1 == 0 && ocp->param2)
	{
		ocp->param1 = ocp->param2;
		ocp->param2 = 0;
	}
}
