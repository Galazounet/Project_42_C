/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_i.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 04:46:15 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/26 21:26:08 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

int					option_i(int *i, t_args *args, t_cv *env)
{
	if (args->av[*i][2] || env->graphical_interface)
		return (USAGE);
	env->graphical_interface = 1;
	if (env->verbose)
		return (USAGE);
	if (env->dump > 0)
		return (USAGE);
	if (ft_isnumber(args->av[(*i) + 1]))
	{
		env->graphical_interface = 1 + (unsigned)ft_atoi(args->av[(*i) + 1]);
		if (env->graphical_interface < 1)
			return (USAGE);
		(*i)++;
	}
	return (SUCCESS);
}
