/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_param_type.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 16:12:49 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:01:58 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "add.h"

int					diff_para_nb(int nb)
{
	int				count;

	count = 0;
	if ((nb & DI) != 0)
		count++;
	if ((nb & IN) != 0)
		count++;
	if ((nb & RE) != 0)
		count++;
	return (count);
}

static inline int	var_xor(int *a, int b)
{
	*a ^= b;
	return (1);
}

void				set_param_type_param(char *msg, int type, int type_nb)
{
	while (type_nb > 0)
	{
		if ((type & DI) != 0 && var_xor(&type, DI) == 1)
			ft_strcat(msg, "`Direct`");
		else if ((type & IN) != 0 && var_xor(&type, IN) == 1)
			ft_strcat(msg, "`Indirect`");
		else if ((type & RE) != 0 && var_xor(&type, RE) == 1)
			ft_strcat(msg, "`Register`");
		if ((type_nb - 1) > 0)
			ft_strcat(msg, " | ");
		type_nb--;
	}
}

t_lexobj			**verify_param_type(t_asm *asmb, t_lexobj *lex, \
	t_inst_meta *meta)
{
	static t_lexobj	*param[INST_MAX_PARAM];
	int				tab[3];

	tab[0] = 0;
	tab[1] = -1;
	tab[2] = count_lexobj(lex) - 1;
	lex = lex->next_obj;
	while (lex)
	{
		param[tab[0]++] = lex;
		lex = lex->next_obj;
	}
	tab[0] = 0;
	while (++tab[1] < tab[2])
		if ((tab[1] % 2) == 1)
		{
			if (is_param_separator(asmb, param[tab[1]], meta) == ERROR)
				return (NULL);
		}
		else
		{
			if (is_param_expected(asmb, param[tab[1]], meta, tab[0]++) == ERROR)
				return (NULL);
		}
	return (param);
}
