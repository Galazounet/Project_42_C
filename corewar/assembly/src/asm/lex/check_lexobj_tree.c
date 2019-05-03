/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lexobj_tree.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 23:24:49 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:02:07 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline char	*msg_by_num(int num)
{
	static char		msg[8][80];

	if (num < 1 && num > 7)
		return (NULL);
	ft_strcpy(msg[LEX_ERR_LABEL_CHAR], "Bad label character in label");
	ft_strcpy(msg[LEX_ERR_NUMBER], "Expected number instead of characters");
	ft_strcpy(msg[LEX_ERR_UNKN_META], \
		"Unknown Header meta, Expected `.name` or `.comment`");
	ft_strcpy(msg[LEX_ERR_EMPTY_LABEL], \
		"Uncomplete label, label name expected after label char (:<nothing>)");
	ft_strcpy(msg[LEX_ERR_UNKN_TYPE], "Unknown data type");
	ft_strcpy(msg[LEX_ERR_NO_NUM_SUGN], \
		"Expected number after sugn (+/-<number>)");
	ft_strcpy(msg[LEX_ERR_LABEL_CALL_CHAR], \
		"Bad label character in label call");
	return (msg[num]);
}

static inline int	verify_lexobj(t_asm *asmb, t_lexobj *lex)
{
	while (lex)
	{
		if (lex->status == STATUS_BAD)
			return (pars_error(asmb, msg_by_num(lex->error), lex, ERROR));
		lex = lex->next_obj;
	}
	return (SUCCESS);
}

int					check_lexobj_tree(t_asm *asmb, t_lexobj *tree)
{
	while (tree)
	{
		if (verify_lexobj(asmb, tree) == ERROR)
			return (ERROR);
		tree = tree->next_line;
	}
	return (SUCCESS);
}
