/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_colors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 06:03:53 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/21 01:08:11 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

void	complete_colors(t_cv *env)
{
	int			i;
	unsigned	j;
	unsigned	len;

	i = 0;
	while (i < env->nb_warriors)
	{
		len = env->warrior[i].initial_pc;
		j = 0;
		while (j < env->warrior[i].len)
		{
			env->vm.parent[j + len] = (unsigned)i + 1;
			j++;
		}
		i++;
	}
}
