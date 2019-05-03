/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexobj_print_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:24:05 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:03:15 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void			lexobj_print_line(t_lexobj *line)
{
	static t_lexobj			*tmp;
	static char				inf[19][100] =
	{"ASM_UNKNOWN", "ASM_COMMENT", "ASM_HEADER_META",
		"ASM_STRING", "ASM_LABEL", "ASM_INSTRUCTION",
		"ASM_REGISTER", "ASM_DIRECT", "ASM_INDIRECT",
		"ASM_SEPARATOR", "ASM_STRING_START", "ASM_STRING_END",
		"ASM_LEBEL_CALL"};

	if (!line)
		return ;
	tmp = line;
	ft_printf("[%3d] ", tmp->line + 1);
	while (tmp)
	{
		if (tmp->status == STATUS_GOOD)
			ft_printf("\e[4m\e[92m%16s\e[39m|\e[24m", inf[tmp->type]);
		else
			ft_printf("\e[4m\e[91m%16s\e[39m|\e[24m", inf[tmp->type]);
		tmp = tmp->next_obj;
	}
	ft_printf("\n");
}

void				lexobj_print_tree(t_lexobj *tree)
{
	t_lexobj		*tmp;

	if (!tree)
		return ;
	tmp = tree;
	while (tmp)
	{
		lexobj_print_line(tmp);
		tmp = tmp->next_line;
	}
}
