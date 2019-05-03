/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_v.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 04:45:29 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/23 00:13:21 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

int					option_v(int *i, t_args *args, t_cv *env)
{
	if (args->av[*i][2] || env->verbose)
		return (USAGE);
	if (env->graphical_interface)
		return (USAGE);
	env->verbose = 1;
	return (SUCCESS);
}
