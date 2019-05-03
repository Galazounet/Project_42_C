/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 23:38:25 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:04:32 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			is_instruction(char *str)
{
	int		i;
	char	*ins;
	int		val;

	if (!str)
		return (ERROR);
	i = 0;
	ins = NULL;
	val = ERROR;
	while (str[i] && is_lex_spearator(str[i]) == 0)
		i++;
	if (i == 0)
		return (ERROR);
	ins = ft_strdupn(str, i);
	if (ft_strcmp(ins, "live") == 0 || ft_strcmp(ins, "ld") == 0 \
		|| ft_strcmp(ins, "st") == 0 || ft_strcmp(ins, "add") == 0 \
		|| ft_strcmp(ins, "sub") == 0 || ft_strcmp(ins, "and") == 0 \
		|| ft_strcmp(ins, "or") == 0 || ft_strcmp(ins, "xor") == 0 \
		|| ft_strcmp(ins, "zjmp") == 0 || ft_strcmp(ins, "ldi") == 0 \
		|| ft_strcmp(ins, "sti") == 0 || ft_strcmp(ins, "fork") == 0 \
		|| ft_strcmp(ins, "lld") == 0 || ft_strcmp(ins, "lldi") == 0 \
		|| ft_strcmp(ins, "lfork") == 0 || ft_strcmp(ins, "aff") == 0)
		val = SUCCESS;
	ft_memdel((void*)&ins);
	return (val);
}
