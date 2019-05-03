/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_indirect.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:06:13 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:04:45 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				lex_indirect(char *str, t_lexobj **moth, \
		unsigned int line, int index)
{
	t_lexobj	*lex;
	int			i;

	if (!str || !moth)
		return (0);
	if (!(lex = lexobj_new(line, index, ASM_INDIRECT)))
		return (0);
	i = 0;
	while (str[i] && is_lex_spearator(str[i]) == 0)
		i++;
	lex->value = ft_strdupn(str, i);
	if ((lex->value[0] == '-' \
		|| lex->value[0] == '+') && ft_strlen(lex->value) == 1)
	{
		lex->status = STATUS_BAD;
		lex->error = LEX_ERR_NO_NUM_SUGN;
	}
	lexobj_push(moth, lex);
	return (i);
}
