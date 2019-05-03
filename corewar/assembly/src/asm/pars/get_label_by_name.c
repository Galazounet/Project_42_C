/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_label_by_name.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:28:05 by suddin            #+#    #+#             */
/*   Updated: 2018/10/06 00:28:22 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		get_label_by_name(t_pars *pars, char *label)
{
	int i;

	if (!label || !pars || !pars->label_name)
		return (ERROR);
	i = 0;
	while (i < pars->label_max)
	{
		if (ft_strcmp(pars->label_name[i], label) == 0)
			return (i);
		i++;
	}
	return (ERROR);
}
