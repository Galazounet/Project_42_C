/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_header_meta.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:04:10 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:04:36 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				lex_header_meta(char *str, t_lexobj **moth, \
		unsigned int line, int index)
{
	t_lexobj	*lex;
	int			i;

	if (!str || !moth)
		return (0);
	if (!(lex = lexobj_new(line, index, ASM_HEADER_META)))
		return (0);
	i = 0;
	while (str[i] && is_lex_spearator(str[i]) == 0)
		i++;
	lex->value = ft_strdupn(str, i);
	if (ft_strcmp(lex->value, NAME_STRING) == 0 \
			|| ft_strcmp(lex->value, COMMENT_STRING) == 0)
		lex->status = STATUS_GOOD;
	else
	{
		lex->status = STATUS_BAD;
		lex->error = LEX_ERR_UNKN_META;
	}
	lexobj_push(moth, lex);
	return (i);
}
