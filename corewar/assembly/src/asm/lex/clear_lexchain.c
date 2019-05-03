/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_lexchain.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 23:26:58 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:02:06 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			clear_lexline(t_lexobj **lex)
{
	t_lexobj	*tlex;

	tlex = NULL;
	while (*lex)
	{
		if ((*lex)->value)
			ft_memdel((void*)&((*lex)->value));
		tlex = (*lex)->next_obj;
		ft_memdel((void*)lex);
		*lex = tlex;
	}
}

void			clear_lexchain(t_lexobj **lex)
{
	t_lexobj	*tlex;

	tlex = NULL;
	while (*lex)
	{
		tlex = (*lex)->next_line;
		clear_lexline(lex);
		*lex = tlex;
	}
}
