/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_inst_by_name.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:24:11 by suddin            #+#    #+#             */
/*   Updated: 2018/10/06 00:27:53 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	get_inst_by_name_ext(char *inst)
{
	if (ft_strcmp(inst, "sti") == 0)
		return (10);
	else if (ft_strcmp(inst, "fork") == 0)
		return (11);
	else if (ft_strcmp(inst, "lld") == 0)
		return (12);
	else if (ft_strcmp(inst, "lldi") == 0)
		return (13);
	else if (ft_strcmp(inst, "lfork") == 0)
		return (14);
	else if (ft_strcmp(inst, "aff") == 0)
		return (15);
	return (ERROR);
}

int			get_inst_by_name(char *inst)
{
	if (!inst)
		return (ERROR);
	if (ft_strcmp(inst, "live") == 0)
		return (0);
	else if (ft_strcmp(inst, "ld") == 0)
		return (1);
	else if (ft_strcmp(inst, "st") == 0)
		return (2);
	else if (ft_strcmp(inst, "add") == 0)
		return (3);
	else if (ft_strcmp(inst, "sub") == 0)
		return (4);
	else if (ft_strcmp(inst, "and") == 0)
		return (5);
	else if (ft_strcmp(inst, "or") == 0)
		return (6);
	else if (ft_strcmp(inst, "xor") == 0)
		return (7);
	else if (ft_strcmp(inst, "zjmp") == 0)
		return (8);
	else if (ft_strcmp(inst, "ldi") == 0)
		return (9);
	else
		return (get_inst_by_name_ext(inst));
}
