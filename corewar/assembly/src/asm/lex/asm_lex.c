/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_lex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/05 23:21:56 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:04:38 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		asm_lex1(char **tab, int *i, int *string_on, t_lexobj **lex)
{
	if (tab[i[0]][i[1]] == COMMENT_CHAR_1 || tab[i[0]][i[1]] == COMMENT_CHAR_2)
		i[1] += lex_comment(&(tab[i[0]][i[1]]));
	else if (tab[i[0]][i[1]] == HEADER_META_CHAR)
		i[1] += lex_header_meta(&(tab[i[0]][i[1]]), lex, i[0], i[1]);
	else if (tab[i[0]][i[1]] == SEPARATOR_CHAR)
		i[1] += lex_separator(&(tab[i[0]][i[1]]), lex, i[0], i[1]);
	else if (tab[i[0]][i[1]] == DIRECT_CHAR)
		i[1] += lex_direct(&(tab[i[0]][i[1]]), lex, i[0], i[1]);
	else if (tab[i[0]][i[1]] == STRING_CHAR)
		i[1] += lex_string(&(tab[i[0]][i[1]]), lex, i, string_on);
	else if (tab[i[0]][i[1]] == LEBEL_LIMIT_CHAR)
		i[1] += lex_label_call(&(tab[i[0]][i[1]]), lex, i[0], i[1]);
	else if (is_register(&(tab[i[0]][i[1]])) == SUCCESS)
		i[1] += lex_register(&(tab[i[0]][i[1]]), lex, i[0], i[1]);
	else if (is_label(&(tab[i[0]][i[1]])) == SUCCESS)
		i[1] += lex_label(&(tab[i[0]][i[1]]), lex, i[0], i[1]);
	else if (is_instruction(&(tab[i[0]][i[1]])) == SUCCESS)
		i[1] += lex_instruction(&(tab[i[0]][i[1]]), lex, i[0], i[1]);
	else if (is_indirect(&(tab[i[0]][i[1]])) == SUCCESS)
		i[1] += lex_indirect(&(tab[i[0]][i[1]]), lex, i[0], i[1]);
	else
		i[1] += lex_unknown(&(tab[i[0]][i[1]]), lex, i[0], i[1]);
	return (i[1]);
}

static int		asm_lex3(char **tab, int string_on, int *i)
{
	if (string_on == 1)
		while (tab[i[0]][i[1]] && tab[i[0]][i[1]] != STRING_CHAR)
			i[1]++;
	while (tab[i[0]][i[1]] && is_space(tab[i[0]][i[1]]) == 1)
		i[1]++;
	return (i[1]);
}

static int		asm_lex4(char **tab, int string_on, unsigned int line, int i)
{
	if (string_on == 1)
		while (tab[line][i] && tab[line][i] != STRING_CHAR)
			i++;
	return (i);
}

t_lexobj		*asm_lex(char **tab, unsigned int line, int string_on,
		t_lexobj *tree)
{
	int			i;
	t_lexobj	*lex;
	int			lx_str[2];

	if (!tab || !(tab[line]))
		return (tree);
	i = asm_lex4(tab, string_on, line, 0);
	lex = NULL;
	while (tab[line][i])
	{
		lx_str[0] = line;
		lx_str[1] = i;
		lx_str[1] = asm_lex3(tab, string_on, lx_str);
		if (!tab[lx_str[0]][lx_str[1]])
			break ;
		lx_str[1] = asm_lex1(tab, lx_str, &string_on, &lex);
		i = lx_str[1];
	}
	if (tree)
	{
		lexobj_push_line(tree, lex);
		return (asm_lex(tab, line + 1, string_on, tree));
	}
	else
		return (asm_lex(tab, line + 1, string_on, lex));
}
