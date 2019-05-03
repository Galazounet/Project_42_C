/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 22:22:36 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/21 22:29:45 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

int	print_cycle(t_cv *env)
{
	if (!env->graphical_interface && env->verbose)
	{
		ft_putstr("It is now cycle ");
		ft_putnbr(env->vm.cycle);
		ft_putendl("");
	}
	return (SUCCESS);
}

int	print_ctd(t_cv *env)
{
	if (!env->graphical_interface && env->verbose)
	{
		ft_putstr("Cycle to die: ");
		ft_putnbr(env->vm.ctd);
		ft_putendl("");
	}
	return (SUCCESS);
}
