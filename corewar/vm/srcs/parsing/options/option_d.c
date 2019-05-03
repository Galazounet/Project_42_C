/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 04:45:59 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/23 00:16:13 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

int					option_d(int *i, t_args *args, t_cv *env)
{
	int tmp;

	if (env->dump > 0)
		return (USAGE);
	if (args->av[*i][2])
		return (USAGE);
	++(*i);
	if (*i >= args->ac || !ft_isnumber(args->av[*i]))
		return (USAGE);
	tmp = ft_atoi(args->av[*i]);
	env->dump = tmp;
	if (env->graphical_interface)
		return (USAGE);
	return (SUCCESS);
}
