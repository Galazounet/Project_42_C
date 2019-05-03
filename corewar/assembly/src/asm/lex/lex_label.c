/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lex_label.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 00:10:44 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:04:42 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				lex_label(char *str, t_lexobj **moth, \
		unsigned int line, int index)
{
	t_lexobj	*lex;
	char		*ext;
	int			i;

	if (!str || !moth)
		return (0);
	if (!(lex = lexobj_new(line, index, ASM_LABEL)))
		return (0);
	i = 0;
	ext = 0;
	while (str[i] && is_lex_spearator(str[i]) == 0)
		i++;
	i += 1;
	lex->value = ft_strdupn(str, i);
	ext = ft_strdupn(str, i - 1);
	if (str_is_label_char(ext) != SUCCESS)
	{
		lex->status = STATUS_BAD;
		lex->error = LEX_ERR_LABEL_CHAR;
	}
	ft_memdel((void*)&ext);
	lexobj_push(moth, lex);
	return (i);
}
