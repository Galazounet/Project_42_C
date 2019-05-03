/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 11:23:56 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:06:23 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ADD_H
# define FT_ADD_H

void			set_inst_meta_name(t_inst_meta *meta);
void			set_inst_meta_param_max(t_inst_meta *meta);
int				is_s_file(char *str);
char			*join_dir_name(char *dir, char *file);
void			count_label_inst(t_lexobj *lex, int *label, int *inst);
char			**make_tab_str(size_t tab_len);
int				*make_array_int(size_t tab_len);
int				is_param_expected(t_asm *asmb, t_lexobj *lex, \
					t_inst_meta *meta, int param_nb);
int				is_param_separator(t_asm *asmb, t_lexobj *param, \
					t_inst_meta *meta);
void			set_param_type_param(char *msg, int type, int type_nb);
int				diff_para_nb(int nb);

typedef struct	s_asm_to_bin
{
	int32_t		first_pad;
	int32_t		second_pad;
	int			bin_len;
	uint32_t	ins_len;
	int			pos;
	uint8_t		*bin;
	int32_t		magic;
}				t_asm_to_bin;

#endif
