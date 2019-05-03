/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar_add.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 15:16:42 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 22:06:30 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COREWAR_ADD_H
# define FT_COREWAR_ADD_H

int				inst_and_set_pc(t_corewar *core, t_vproc *proc, int32_t *p_s);
void			init_reg_bf_name(t_corewar *core);
void			init_reg_bf(t_corewar *core);
void			init_reg_af_name(t_corewar *core);
void			init_reg_af(t_corewar *core);
void			init_core1(t_corewar *core);
void			init_core2(t_corewar *core);
void			init_winbox1(t_corewar *core);
void			set_window_box(t_corewar *core);
void			init_core_process(t_corewar *core);
void			init_core_numname(t_corewar *core);
void			refresh_windows(t_corewar *core);
void			refresh_win1(t_corewar *core);
void			pair_color_start(void);
void			init_mem_win(t_corewar *core);
void			init_box(t_corewar *core);
int				check_data(t_corewar *core);
int				create_windows(t_corewar *core);
void			set_player_name(t_corewar *core);
void			set_player_number(t_corewar *core);
void			set_general_core_info(t_corewar *core);
void			set_proc_head(t_corewar *core);
void			set_button(t_corewar *core);
void			update_cycle(t_corewar *core);
void			init_core_tres(t_corewar *cor);
void			init_core_dos(t_corewar *cor);
uint8_t			*inst_and_gen_mem(t_corewar *core, t_warrior *warr,
		t_vproc *proc);
int				inst_and_if(t_corewar *core, t_vproc *proc, int32_t *param,
		int32_t *type);
int				inst_xor_if(t_corewar *core, t_vproc *proc, int32_t *param,
		int32_t *type);
uint8_t			*load_mem_inst(t_corewar *core, t_warrior *warr,
		t_vproc *proc);
int32_t			inst_set_param0(t_corewar *core, t_vproc *proc, int32_t *type,
		int32_t *param);
int32_t			inst_set_param1(t_corewar *core, t_vproc *proc, int32_t *type,
		int32_t *param);
int				inst_set_pc_error(t_corewar *core, t_vproc *proc, int32_t val,
		int val2);
int				inst_set_pc_success(t_corewar *core, t_vproc *proc, int32_t val,
		int val2);

#endif
