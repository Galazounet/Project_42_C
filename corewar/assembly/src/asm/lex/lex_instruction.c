/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_instruction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:08:06 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:04:40 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				lex_instruction(char *str, t_lexobj **moth, \
		unsigned int line, int index)
{
	t_lexobj	*lex;
	int			i;

	if (!str || !moth)
		return (0);
	if (!(lex = lexobj_new(line, index, ASM_INSTRUCTION)))
		return (0);
	i = 0;
	while (str[i] && is_lex_spearator(str[i]) == 0)
		i++;
	lex->value = ft_strdupn(str, i);
	lexobj_push(moth, lex);
	return (i);
}
