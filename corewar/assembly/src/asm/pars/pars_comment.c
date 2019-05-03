/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:32:21 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:03:16 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		error_pars_comment(int obj_count, t_asm *asmb, t_lexobj **lex)
{
	if (obj_count < 2)
	{
		return (pars_error(asmb,
					"Too few argument for Header Meta 'comment'", *lex,
					ERROR));
	}
	else if (obj_count > 3)
	{
		return (pars_error(asmb, "To many argumetn for Header Meta 'comment'",
					*lex, ERROR));
	}
	return (SUCCESS);
}

static int		error_pars_comment2(t_asm *asmb, t_lexobj *start, t_lexobj *end)
{
	if (start && start->type != ASM_STRING_START)
		return (pars_error(asmb, "Expected String Start `", start, ERROR));
	if (!end)
		return (pars_error(asmb, "String type is not done", start, ERROR));
	if (end->next_obj != NULL)
		return (pars_error(asmb, "error", end->next_obj, ERROR));
	return (SUCCESS);
}

static int		error_pars_comment3(t_asm *asmb, t_lexobj **lex,
		t_pars *pars, t_lexobj *end)
{
	if (pars->comment_len == 0)
		return (pars_error(asmb, "Header Meta `comment`", *lex, WARNING));
	if (pars->comment_len > COMMENT_SIZE)
		return (pars_error(asmb, "Header Meta `comment`", *lex, WARNING));
	*lex = end;
	return (SUCCESS);
}

int				pars_comment(t_asm *asmb, char **tab, t_lexobj **lex,
		t_pars *pars)
{
	int			obj_count;
	t_lexobj	*start;
	t_lexobj	*end;

	obj_count = 0;
	start = NULL;
	end = NULL;
	obj_count = count_lexobj(*lex);
	if ((*lex) && ((*lex)->type != ASM_HEADER_META \
				|| ft_strcmp((*lex)->value, COMMENT_STRING)) != 0)
		return (pars_error(asmb, "Expected Header Meta `comment`",
					*lex, ERROR));
	else if (error_pars_comment(obj_count, asmb, lex) == ERROR)
		return (ERROR);
	start = get_next_lexobj((*lex));
	end = get_next_lexobj(start);
	if (error_pars_comment2(asmb, start, end) == ERROR)
		return (ERROR);
	pars->comment = get_string_pars(tab, start, end);
	pars->comment_len = ft_strlen(pars->comment) - 1;
	pars->comment[pars->comment_len] = 0;
	return (error_pars_comment3(asmb, lex, pars, end));
}
