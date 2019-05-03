/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_direct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:02:27 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:04:35 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		lex_direct2(t_lexobj *lex, int len)
{
	if (len > 1 && (lex->value)[1] == LEBEL_LIMIT_CHAR)
	{
		if (str_is_label_char(&((lex->value)[2])) == SUCCESS)
			lex->status = STATUS_GOOD;
		else
		{
			lex->status = STATUS_BAD;
			lex->error = LEX_ERR_LABEL_CHAR;
		}
	}
	else if (str_is_numer(&((lex->value)[1])) == SUCCESS)
		lex->status = STATUS_GOOD;
	else
	{
		lex->status = STATUS_BAD;
		lex->error = LEX_ERR_NUMBER;
	}
}

int				lex_direct(char *str, t_lexobj **moth, unsigned int line,
		int index)
{
	t_lexobj	*lex;
	int			i;
	int			len;

	if (!str || !moth)
		return (0);
	if (!(lex = lexobj_new(line, index, ASM_DIRECT)))
		return (0);
	i = 1;
	len = ft_strlen(str);
	if (len > 2 && str[1] == LEBEL_LIMIT_CHAR)
		i = 2;
	while (str[i] && is_lex_spearator(str[i]) == 0)
		i++;
	lex->value = ft_strdupn(str, i);
	lex_direct2(lex, len);
	lexobj_push(moth, lex);
	return (i);
}
