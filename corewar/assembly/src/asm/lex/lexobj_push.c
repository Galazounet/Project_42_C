/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexobj_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:24:22 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:03:13 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			lexobj_push(t_lexobj **mother, t_lexobj *child)
{
	t_lexobj	*lex;

	if (!mother || !child)
		return ;
	if (!(*mother))
		*mother = child;
	else
	{
		lex = *mother;
		while (lex && lex->next_obj)
			lex = lex->next_obj;
		lex->next_obj = child;
	}
}
