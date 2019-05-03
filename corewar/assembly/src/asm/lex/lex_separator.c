/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_separator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:16:52 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:04:49 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				lex_separator(char *str, t_lexobj **moth, \
		unsigned int line, int index)
{
	t_lexobj	*lex;

	if (!str || !moth)
		return (0);
	if (!(lex = lexobj_new(line, index, ASM_SEPARATOR)))
		return (0);
	lex->value = ft_strdupn(str, 1);
	lexobj_push(moth, lex);
	return (1);
}
