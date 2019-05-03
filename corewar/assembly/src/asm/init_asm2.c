/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asm2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 15:28:04 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:02:11 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "add.h"

void		set_inst_meta_name(t_inst_meta *meta)
{
	ft_strcpy(meta[INST_INDEX_LIVE].name, "live");
	ft_strcpy(meta[INST_INDEX_LD].name, "ld");
	ft_strcpy(meta[INST_INDEX_ST].name, "st");
	ft_strcpy(meta[INST_INDEX_ADD].name, "add");
	ft_strcpy(meta[INST_INDEX_SUB].name, "sub");
	ft_strcpy(meta[INST_INDEX_AND].name, "and");
	ft_strcpy(meta[INST_INDEX_OR].name, "or");
	ft_strcpy(meta[INST_INDEX_XOR].name, "xor");
	ft_strcpy(meta[INST_INDEX_ZJMP].name, "zjmp");
	ft_strcpy(meta[INST_INDEX_LDI].name, "ldi");
	ft_strcpy(meta[INST_INDEX_STI].name, "sti");
	ft_strcpy(meta[INST_INDEX_FORK].name, "fork");
	ft_strcpy(meta[INST_INDEX_LLD].name, "lld");
	ft_strcpy(meta[INST_INDEX_LLDI].name, "lldi");
	ft_strcpy(meta[INST_INDEX_LFORK].name, "lfork");
	ft_strcpy(meta[INST_INDEX_AFF].name, "aff");
}

void		set_inst_meta_param_max(t_inst_meta *meta)
{
	meta[INST_INDEX_LIVE].max_param = 1;
	meta[INST_INDEX_LD].max_param = 2;
	meta[INST_INDEX_ST].max_param = 2;
	meta[INST_INDEX_ADD].max_param = 3;
	meta[INST_INDEX_SUB].max_param = 3;
	meta[INST_INDEX_AND].max_param = 3;
	meta[INST_INDEX_OR].max_param = 3;
	meta[INST_INDEX_XOR].max_param = 3;
	meta[INST_INDEX_ZJMP].max_param = 1;
	meta[INST_INDEX_LDI].max_param = 3;
	meta[INST_INDEX_STI].max_param = 3;
	meta[INST_INDEX_FORK].max_param = 1;
	meta[INST_INDEX_LLD].max_param = 2;
	meta[INST_INDEX_LLDI].max_param = 3;
	meta[INST_INDEX_LFORK].max_param = 1;
	meta[INST_INDEX_AFF].max_param = 1;
}
