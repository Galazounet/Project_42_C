/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexobj_push_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:25:09 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:03:14 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline void	lexobj_set_next_line(t_lexobj *obj, t_lexobj *next_line)
{
	if (!obj || !next_line)
		return ;
	while (obj)
	{
		obj->next_line = next_line;
		obj = obj->next_obj;
	}
}

void				lexobj_push_line(t_lexobj *tree, t_lexobj *lex)
{
	t_lexobj		*tmp;

	if (!lex || !tree)
		return ;
	tmp = tree;
	while (tmp && tmp->next_line)
	{
		lexobj_set_next_line(tmp, tmp->next_line);
		tmp = tmp->next_line;
	}
	lexobj_set_next_line(tmp, lex);
	tmp->next_line = lex;
}
