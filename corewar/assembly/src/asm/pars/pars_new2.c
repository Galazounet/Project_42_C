/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_new2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 21:01:29 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:03:18 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "add.h"

void				count_label_inst(t_lexobj *lex, int *label, int *inst)
{
	int				lbl;
	int				ins;

	if (!lex)
		return ;
	lbl = 0;
	ins = 0;
	while (lex)
	{
		if (lex->type == ASM_LABEL)
			lbl++;
		else if (lex->type == ASM_INSTRUCTION)
			ins++;
		lex = get_next_lexobj(lex);
	}
	*label = lbl;
	*inst = ins;
}

char				**make_tab_str(size_t tab_len)
{
	char			**tab;
	size_t			i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * (tab_len + 1));
	if (!tab)
		return (NULL);
	while (i < tab_len + 1)
	{
		tab[i] = NULL;
		i++;
	}
	return (tab);
}

int					*make_array_int(size_t tab_len)
{
	int				*tab;
	size_t			i;

	i = 0;
	tab = (int *)malloc(sizeof(int) * (tab_len + 1));
	if (!tab)
		return (NULL);
	while (i < tab_len + 1)
	{
		tab[i] = 0;
		i++;
	}
	return (tab);
}
