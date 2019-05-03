/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/01 14:20:51 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:02:05 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "add.h"

void					ini_arr(int *arr, int a, int b, int c)
{
	arr[0] = a;
	arr[1] = b;
	arr[2] = c;
	arr[3] = 0;
}

static inline void		set_inst_meta_param_type(t_inst_meta *meta)
{
	ini_arr(meta[INST_INDEX_LIVE].param_type, DI, 0, 0);
	ini_arr(meta[INST_INDEX_LD].param_type, DI | IN, RE, 0);
	ini_arr(meta[INST_INDEX_ST].param_type, RE, IN | RE, 0);
	ini_arr(meta[INST_INDEX_ADD].param_type, RE, RE, RE);
	ini_arr(meta[INST_INDEX_SUB].param_type, RE, RE, RE);
	ini_arr(meta[INST_INDEX_AND].param_type, RE | DI | IN, RE | DI | IN, RE);
	ini_arr(meta[INST_INDEX_OR].param_type, RE | DI | IN, RE | DI | IN, RE);
	ini_arr(meta[INST_INDEX_XOR].param_type, RE | DI | IN, RE | DI | IN, RE);
	ini_arr(meta[INST_INDEX_ZJMP].param_type, DI, 0, 0);
	ini_arr(meta[INST_INDEX_LDI].param_type, RE | DI | IN, RE | DI, RE);
	ini_arr(meta[INST_INDEX_STI].param_type, RE, RE | DI | IN, RE | DI);
	ini_arr(meta[INST_INDEX_FORK].param_type, DI, 0, 0);
	ini_arr(meta[INST_INDEX_LLD].param_type, DI | IN, RE, 0);
	ini_arr(meta[INST_INDEX_LLDI].param_type, RE | DI | IN, RE | DI, RE);
	ini_arr(meta[INST_INDEX_LFORK].param_type, DI, 0, 0);
	ini_arr(meta[INST_INDEX_AFF].param_type, RE, 0, 0);
}

static inline void		set_inst_meta_direct_size(t_inst_meta *meta)
{
	meta[INST_INDEX_LIVE].direct_size = 1;
	meta[INST_INDEX_LD].direct_size = 1;
	meta[INST_INDEX_ST].direct_size = 1;
	meta[INST_INDEX_ADD].direct_size = 1;
	meta[INST_INDEX_SUB].direct_size = 1;
	meta[INST_INDEX_AND].direct_size = 1;
	meta[INST_INDEX_OR].direct_size = 1;
	meta[INST_INDEX_XOR].direct_size = 1;
	meta[INST_INDEX_ZJMP].direct_size = 2;
	meta[INST_INDEX_LDI].direct_size = 2;
	meta[INST_INDEX_STI].direct_size = 2;
	meta[INST_INDEX_FORK].direct_size = 2;
	meta[INST_INDEX_LLD].direct_size = 1;
	meta[INST_INDEX_LLDI].direct_size = 2;
	meta[INST_INDEX_LFORK].direct_size = 2;
	meta[INST_INDEX_AFF].direct_size = 1;
}

static inline void		set_inst_meta_encoded(t_inst_meta *meta)
{
	meta[INST_INDEX_LIVE].encoded = 0;
	meta[INST_INDEX_LD].encoded = 1;
	meta[INST_INDEX_ST].encoded = 1;
	meta[INST_INDEX_ADD].encoded = 1;
	meta[INST_INDEX_SUB].encoded = 1;
	meta[INST_INDEX_AND].encoded = 1;
	meta[INST_INDEX_OR].encoded = 1;
	meta[INST_INDEX_XOR].encoded = 1;
	meta[INST_INDEX_ZJMP].encoded = 0;
	meta[INST_INDEX_LDI].encoded = 1;
	meta[INST_INDEX_FORK].encoded = 0;
	meta[INST_INDEX_STI].encoded = 1;
	meta[INST_INDEX_LLD].encoded = 1;
	meta[INST_INDEX_LLDI].encoded = 1;
	meta[INST_INDEX_LFORK].encoded = 0;
	meta[INST_INDEX_AFF].encoded = 1;
}

void					init_asm(t_asm *asmb)
{
	asmb->flag = 0;
	asmb->curr_file = NULL;
	asmb->curr_lex = NULL;
	asmb->file_q_len = 0;
	asmb->file_q = NULL;
	asmb->fname_len = 0;
	asmb->fname = NULL;
	asmb->arg_name = NULL;
	asmb->arg_name_len = 0;
	set_inst_meta_name(asmb->inst_meta);
	set_inst_meta_param_max(asmb->inst_meta);
	set_inst_meta_param_type(asmb->inst_meta);
	set_inst_meta_direct_size(asmb->inst_meta);
	set_inst_meta_encoded(asmb->inst_meta);
}
