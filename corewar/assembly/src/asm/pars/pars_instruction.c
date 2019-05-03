/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_instruction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 17:41:51 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 21:39:31 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	pars_instruction0(t_asm *asmb, t_lexobj **lex, t_pars *pars)
{
	if (get_inst_by_name((*lex)->value) == ERROR)
		return (ERROR);
	if (set_inst(asmb, *lex, pars, &(pars->inst_table[pars->inst_count]))
		== ERROR)
	{
		return (ERROR);
	}
	pars->inst_count++;
	*lex = (*lex)->next_line;
	return (SUCCESS);
}

int			pars_instruction(t_asm *asmb, t_lexobj *lex, t_pars *pars)
{
	int		label;

	label = 0;
	if (!lex)
		return (pars_error(asmb, "No instructions", NULL, WARNING));
	while (lex)
	{
		if (lex->type == ASM_LABEL)
		{
			pars->label_tab[label++] = pars->inst_section_len;
			lex = get_next_lexobj(lex);
		}
		else if (lex->type == ASM_INSTRUCTION)
		{
			if (pars_instruction0(asmb, &lex, pars) == ERROR)
				return (ERROR);
		}
		else
			return (pars_error(asmb, \
						"Expected instruction or label declaration", lex,
						ERROR));
	}
	if (pars->inst_max == 0)
		return (pars_error(asmb, "No instructions", NULL, WARNING));
	return (SUCCESS);
}
