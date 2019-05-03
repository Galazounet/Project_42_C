/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexobj_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:22:35 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:04:54 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_lexobj		*lexobj_new(unsigned int line, int index, int type)
{
	t_lexobj	*lex;

	if (!(lex = (t_lexobj *)malloc(sizeof(t_lexobj))))
		return (NULL);
	lex->line = line;
	lex->start_index = index;
	lex->type = type;
	lex->value = NULL;
	lex->status = STATUS_GOOD;
	lex->error = 0;
	lex->next_obj = NULL;
	lex->next_line = NULL;
	return (lex);
}
