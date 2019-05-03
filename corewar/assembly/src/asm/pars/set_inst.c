/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: suddin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 01:19:54 by suddin            #+#    #+#             */
/*   Updated: 2018/10/07 12:22:01 by suddin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static inline int	get_instruction_index_by_name(t_asm *asmb, char *inst)
{
	int i;

	if (!asmb || !inst)
		return (ERROR);
	i = 0;
	while (i < INST_INDEX_MAX)
	{
		if (ft_strcmp(asmb->inst_meta[i].name, inst) == 0)
			return (i);
		i++;
	}
	return (ERROR);
}

int					set_para_size(t_asm *asmb, t_inst *inst)
{
	int i;
	int total;
	int direct_size;

	if (!asmb || !inst)
		return (0);
	i = 0;
	total = 0;
	direct_size = asmb->inst_meta[inst->inst].direct_size;
	while (i < asmb->inst_meta[inst->inst].max_param)
	{
		if (inst->arg_type[i] == ASM_REGISTER)
			inst->arg_size[i] = SIZE_REGISTER;
		else if (inst->arg_type[i] == ASM_DIRECT \
				|| inst->arg_type[i] == ASM_LEBEL_DIRECT)
			inst->arg_size[i] = SIZE_DIRECT / direct_size;
		else if (inst->arg_type[i] == ASM_INDIRECT \
				|| inst->arg_type[i] == ASM_LEBEL_INDIRECT)
			inst->arg_size[i] = SIZE_INDIRECT;
		total += inst->arg_size[i];
		i++;
	}
	return (total);
}

uint8_t				set_nth_param_bit(uint8_t src, int n)
{
	if (n == 0)
		src = src << 6;
	else if (n == 1)
		src = src << 4;
	else if (n == 2)
		src = src << 2;
	return (src);
}

uint8_t				set_encode(t_asm *asmb, t_inst *inst)
{
	uint8_t	enc;
	int		i;

	i = 0;
	enc = 0;
	while (i < asmb->inst_meta[inst->inst].max_param)
	{
		if (inst->arg_type[i] == ASM_REGISTER)
			enc |= set_nth_param_bit(ENCODED_REGISTER, i);
		else if (inst->arg_type[i] == ASM_DIRECT \
				|| inst->arg_type[i] == ASM_LEBEL_DIRECT)
			enc |= set_nth_param_bit(ENCODED_DIRECT, i);
		else if (inst->arg_type[i] == ASM_INDIRECT \
				|| inst->arg_type[i] == ASM_LEBEL_INDIRECT)
			enc |= set_nth_param_bit(ENCODED_INDIRECT, i);
		i++;
	}
	return (enc);
}

int					set_inst(t_asm *asmb, t_lexobj \
		*lex, t_pars *pars, t_inst *inst)
{
	t_lexobj **param;

	if (!asmb || !lex || !pars || !inst)
		return (ERROR);
	inst->inst = get_instruction_index_by_name(asmb, lex->value);
	param = NULL;
	pars->tmp_param_nb = 0;
	pars->tmp_param_curr = 0;
	pars->tmp_param_count = 0;
	if ((pars->tmp_param_count = param_len_verify(asmb, lex, \
					&(asmb->inst_meta[inst->inst]))) == ERROR)
		return (ERROR);
	if ((param = verify_param_type(asmb, lex, \
					&(asmb->inst_meta[inst->inst]))) == NULL)
		return (ERROR);
	if (set_param(asmb, param, pars, inst) == ERROR)
		return (ERROR);
	inst->mem_index = pars->inst_section_len;
	inst->total_inst_size = 1 + asmb->inst_meta[inst->inst].encoded;
	inst->total_inst_size += set_para_size(asmb, inst);
	inst->encoded = set_encode(asmb, inst);
	pars->inst_section_len += inst->total_inst_size;
	return (SUCCESS);
}
