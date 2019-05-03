/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_header.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:30:32 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:05:35 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int	pars_header(t_asm *asmb, char **tab, t_lexobj **lex, t_pars *pars)
{
	if (pars_name(asmb, tab, lex, pars) == ERROR)
		return (ERROR);
	(*lex) = (*lex)->next_line;
	if (pars_comment(asmb, tab, lex, pars) == ERROR)
		return (ERROR);
	(*lex) = (*lex)->next_line;
	return (SUCCESS);
}
