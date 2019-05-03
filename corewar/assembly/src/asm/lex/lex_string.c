/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:18:04 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:04:53 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				lex_string(char *str, t_lexobj **moth, \
		int *lx_str, int *strin_end)
{
	t_lexobj	*lex;

	if (!str || !moth)
		return (0);
	if (!(lex = lexobj_new(lx_str[STR_LINE], lx_str[STR_INDEX], \
		(*strin_end == 1) ? ASM_STRING_END : ASM_STRING_START)))
		return (0);
	if (*strin_end == 1)
		*strin_end = 0;
	else
		*strin_end = 1;
	lexobj_push(moth, lex);
	return (1);
}
