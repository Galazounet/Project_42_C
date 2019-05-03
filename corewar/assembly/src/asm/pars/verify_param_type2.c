/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_param_type2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 21:07:08 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:03:02 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "add.h"

int					is_param_expected(t_asm *asmb, t_lexobj *lex,
		t_inst_meta *meta, int param_nb)
{
	int				type;
	char			msg[100];
	int				type_nb;

	type = meta->param_type[param_nb];
	type_nb = diff_para_nb(meta->param_type[param_nb]);
	if ((type & DI) && lex->type == ASM_DIRECT)
		return (SUCCESS);
	else if ((type & IN) && (lex->type == ASM_INDIRECT \
		|| lex->type == ASM_LEBEL_CALL))
		return (SUCCESS);
	else if ((type & RE) && lex->type == ASM_REGISTER)
		return (SUCCESS);
	else
	{
		ft_memset(msg, 0, 100);
		ft_strcpy(msg, "Unexpected parameter type for instruction `");
		ft_strcat(msg, meta->name);
		ft_strcat(msg, "`. Expected: [");
		set_param_type_param(msg, type, type_nb);
		ft_strcat(msg, "] types.");
		return (pars_error(asmb, msg, lex, ERROR));
	}
}

int					is_param_separator(t_asm *asmb, t_lexobj *param,
	t_inst_meta *meta)
{
	char			msg[100];

	ft_memset(msg, 0, 100);
	if (param->type != ASM_SEPARATOR)
	{
		ft_strcpy(msg, "Unexpected parameter for instruction `");
		ft_strcat(msg, meta->name);
		ft_strcat(msg, "`. Expected `,` (separator) type as parameter.");
		return (pars_error(asmb, msg, param, ERROR));
	}
	return (SUCCESS);
}
