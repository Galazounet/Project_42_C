/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_label_call.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:13:18 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:04:43 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				lex_label_call(char *str, t_lexobj **moth, \
		unsigned int line, int index)
{
	t_lexobj	*lex;
	int			i;

	if (!str || !moth)
		return (0);
	if (!(lex = lexobj_new(line, index, ASM_LEBEL_CALL)))
		return (0);
	i = 1;
	while (str[i] && is_lex_spearator(str[i]) == 0)
		i++;
	lex->value = ft_strdupn(str, i);
	if (ft_strlen(lex->value) == 1)
	{
		lex->status = STATUS_BAD;
		lex->error = LEX_ERR_EMPTY_LABEL;
	}
	else if (str_is_label_char(&(lex->value[2])) != SUCCESS)
	{
		lex->status = STATUS_BAD;
		lex->error = LEX_ERR_LABEL_CALL_CHAR;
	}
	lexobj_push(moth, lex);
	return (i);
}
