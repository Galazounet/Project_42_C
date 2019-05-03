/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 01:18:01 by suddin            #+#    #+#             */
/*   Updated: 2018/10/06 21:02:14 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "add.h"

static inline int	copy_label(t_lexobj *lex, char **tab, int tab_len)
{
	int				i;

	if (!lex || !tab)
		return (ERROR);
	i = 0;
	while (i < tab_len && lex)
	{
		if (lex->type == ASM_LABEL)
		{
			tab[i] = ft_strdupn(lex->value, ft_strlen(lex->value) - 1);
			if (tab[i] == NULL)
				return (ERROR);
			i++;
		}
		lex = get_next_lexobj(lex);
	}
	return (SUCCESS);
}

void				init_inst(t_inst *inst)
{
	inst->inst = 0;
	inst->encoded = 0;
	inst->mem_index = 0;
	inst->arg[0] = 0;
	inst->arg[1] = 0;
	inst->arg[2] = 0;
	inst->arg[3] = 0;
	inst->arg_type[0] = 0;
	inst->arg_type[1] = 0;
	inst->arg_type[2] = 0;
	inst->arg_type[3] = 0;
	inst->arg_size[0] = 0;
	inst->arg_size[1] = 0;
	inst->arg_size[2] = 0;
	inst->arg_size[3] = 0;
	inst->total_inst_size = 0;
}

t_inst				*inst_new(int size)
{
	t_inst			*tab;
	int				i;

	i = 0;
	if (!(tab = (t_inst *)malloc(sizeof(t_inst) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		init_inst(&(tab[i]));
		i++;
	}
	return (tab);
}

static void			pars_new_inlint(t_pars *pars)
{
	pars->name = NULL;
	pars->name_len = 0;
	pars->comment = NULL;
	pars->comment_len = 0;
	pars->inst_section_len = 0;
	pars->inst_section_len = 0;
	pars->label_name = NULL;
	pars->label_max = 0;
	pars->label_tab = NULL;
	pars->inst_table = NULL;
	pars->inst_count = 0;
	pars->inst_max = 0;
	pars->tmp_param_nb = 0;
	pars->bin = NULL;
}

t_pars				*pars_new(t_lexobj *lex)
{
	t_pars			*pars;

	if (!(pars = (t_pars *)malloc(sizeof(t_pars))))
		return (NULL);
	pars_new_inlint(pars);
	count_label_inst(lex, &(pars->label_max), &(pars->inst_max));
	if (pars->label_max > 0)
	{
		pars->label_name = make_tab_str(pars->label_max);
		pars->label_tab = make_array_int(pars->label_max);
		if (copy_label(lex, pars->label_name, pars->label_max) == ERROR)
		{
			free_pars(&pars);
			return (NULL);
		}
	}
	if (pars->inst_max > 0)
	{
		if ((pars->inst_table = inst_new(pars->inst_max)) == NULL)
		{
			free_pars(&pars);
			return (NULL);
		}
	}
	return (pars);
}
