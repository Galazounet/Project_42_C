/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_to_binary.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:40:01 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 21:42:08 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "add.h"

static inline void		replace_label(t_asm *asmb, t_pars *pars, t_inst *inst)
{
	int				i;
	int				*label_tab;

	i = 0;
	label_tab = pars->label_tab;
	while (i < asmb->inst_meta[inst->inst].max_param)
	{
		if (inst->arg_type[i] == ASM_LEBEL_DIRECT ||\
				inst->arg_type[i] == ASM_LEBEL_INDIRECT)
		{
			inst->arg[i] = label_tab[inst->arg[i]] - inst->mem_index;
			if (inst->arg_type[i] == ASM_LEBEL_DIRECT)
				inst->arg_type[i] = ASM_LEBEL_DIRECT;
			else
				inst->arg_type[i] = ASM_LEBEL_INDIRECT;
		}
		i++;
	}
}

static inline uint32_t	big_end(uint32_t val, int size)
{
	uint32_t	nv;

	nv = 0;
	if (size == 1)
		nv = val;
	else if (size == 2)
	{
		val = (uint16_t)val;
		nv |= (uint32_t)((uint16_t)val << 8);
		nv |= (val >> 8);
	}
	else if (size == 4)
	{
		nv |= val >> 24;
		nv |= ((val >> 16) << 24) >> 16;
		nv |= ((val >> 8) << 24) >> 8;
		nv |= (val << 24);
	}
	return (nv);
}

int						inst_to_bin(t_asm *asmb, t_pars *pars, uint8_t *bin,
		int pos)
{
	int				i;
	int				arg;
	int				big;
	t_inst			*inst;

	i = 0;
	inst = pars->inst_table;
	while (i < pars->inst_count)
	{
		arg = 0;
		big = 0;
		replace_label(asmb, pars, &(inst[i]));
		bin[pos++] = inst[i].inst + 1;
		if (asmb->inst_meta[inst[i].inst].encoded != 0)
			bin[pos++] = inst[i].encoded;
		while (arg < asmb->inst_meta[inst[i].inst].max_param)
		{
			big = big_end(inst[i].arg[arg], inst[i].arg_size[arg]);
			ft_memcpy(&(bin[pos]), &big, inst[i].arg_size[arg]);
			pos += inst[i].arg_size[arg];
			arg++;
		}
		i++;
	}
	return (pos);
}

static int				pars_to_binary2(t_asm *asmb, t_pars *pars,
		t_asm_to_bin a)
{
	if (!(a.bin = (uint8_t *)malloc(sizeof(uint8_t) * a.bin_len)))
	{
		return (pars_error(asmb, "Couldn't allocate memory in pars_to_binary",
					NULL, ERROR));
	}
	ft_memset(a.bin, 0, a.bin_len);
	ft_memcpy(&(a.bin[a.pos]), &a.magic, sizeof(uint32_t));
	a.pos += sizeof(uint32_t);
	ft_memcpy(&(a.bin[a.pos]), pars->name, (pars->name_len > NAME_SIZE) ?
			NAME_SIZE : pars->name_len);
	a.pos += NAME_SIZE;
	ft_memcpy(&(a.bin[a.pos]), &a.first_pad, sizeof(a.first_pad));
	a.pos += (sizeof(a.first_pad));
	ft_memcpy(&(a.bin[a.pos]), &a.ins_len, sizeof(a.ins_len));
	a.pos += (sizeof(a.ins_len));
	ft_memcpy(&(a.bin[a.pos]), pars->comment, (pars->comment_len
				> COMMENT_SIZE) ? COMMENT_SIZE : pars->comment_len);
	a.pos += COMMENT_SIZE;
	ft_memcpy(&(a.bin[a.pos]), &a.second_pad, sizeof(a.second_pad));
	a.pos += (sizeof(a.second_pad));
	a.pos = inst_to_bin(asmb, pars, a.bin, a.pos);
	pars->bin = a.bin;
	pars->bin_len = a.bin_len;
	return (SUCCESS);
}

int						pars_to_binary(t_asm *asmb, t_pars *pars)
{
	t_asm_to_bin	binary;

	binary.bin = NULL;
	binary.pos = 0;
	binary.first_pad = 0;
	binary.second_pad = 0;
	binary.magic = big_end(MAGIC_NUMBER, 4);
	binary.bin_len = (HEADER_LEN + pars->inst_section_len + 8);
	binary.ins_len = (uint64_t)big_end(pars->inst_section_len, 4);
	if (!asmb || !pars)
		return (ERROR);
	return (pars_to_binary2(asmb, pars, binary));
}
