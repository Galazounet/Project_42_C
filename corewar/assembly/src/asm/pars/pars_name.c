/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:37:24 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:03:17 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				pars_name_ext(t_asm *asmb, t_lexobj **lex, t_lexobj **start,
		t_lexobj **end)
{
	*start = get_next_lexobj(*lex);
	if ((*start) && (*start)->type != ASM_STRING_START)
	{
		return (pars_error(asmb, "Expected String Start type `\"` type "
					"as argument for Header Meta 'name'", *start, ERROR));
	}
	*end = get_next_lexobj(*start);
	if (!(*end))
	{
		return (pars_error(asmb, "String type is not complete, "
					"expected String End type `\"`", *start, ERROR));
	}
	if ((*end)->next_obj != NULL)
	{
		return (pars_error(asmb, "String type is not complete, "
					"expected String End type `\"`", (*end)->next_obj, ERROR));
	}
	return (SUCCESS);
}

int				pars_name(t_asm *asmb, char **tab, t_lexobj **lex, t_pars *pars)
{
	int			obj_count;
	t_lexobj	*start;
	t_lexobj	*end;

	obj_count = 0;
	start = NULL;
	end = NULL;
	obj_count = count_lexobj(*lex);
	if ((*lex) && ((*lex)->type != ASM_HEADER_META \
				|| ft_strcmp((*lex)->value, NAME_STRING)) != 0)
		return (pars_error(asmb, "Expected Header Meta `name`", *lex, ERROR));
	else if (obj_count < 2)
		return (pars_error(asmb, "Too few argument for Header Meta 'name'"
					" expected only 1 string type as argument", *lex, ERROR));
		pars_name_ext(asmb, lex, &start, &end);
	pars->name = get_string_pars(tab, start, end);
	pars->name_len = ft_strlen(pars->name) - 1;
	pars->name[pars->name_len] = 0;
	if (pars->name_len == 0)
		return (pars_error(asmb, "Header Meta `name` do not "
					"contain any string value", *lex, WARNING));
	else if (pars->name_len > NAME_SIZE)
		return (pars_error(asmb, "Header Meta `name` too big", *lex, WARNING));
	*lex = end;
	return (SUCCESS);
}
