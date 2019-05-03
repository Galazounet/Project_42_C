/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mempointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 12:25:57 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/19 21:46:28 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

int	set_mempointer(t_cv *env)
{
	unsigned spacement;
	unsigned actual;
	unsigned i;

	spacement = MEM_SIZE / env->nb_warriors;
	actual = 0;
	i = 0;
	ft_bzero(env->vm.memory, MEM_SIZE);
	ft_bzero(env->vm.parent, MEM_SIZE * sizeof(int));
	while (i < env->nb_warriors)
	{
		env->warrior[i].instructions = env->vm.memory + actual;
		env->warrior[i].initial_pc = actual;
		actual += spacement;
		++i;
	}
	return (SUCCESS);
}
