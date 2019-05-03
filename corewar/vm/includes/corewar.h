/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 02:14:39 by afrangio          #+#    #+#             */
/*   Updated: 2019/02/27 23:13:41 by dygouasd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# include <stdint.h>
# include <limits.h>
# include "vm.h"
# include "types.h"
# include "colors.h"
# include "graphical_interface.h"
# include "error_handling.h"
# include "op.h"
# include <ncurses.h>

/*
** Parsing functions
*/
int					arguments_parser(t_args *args, t_cv *env);
int					verify_extention(char *s, t_cv *env);

/*
** Options handling
*/
int					arg_champ(int *i, t_args *args, t_cv *env);
int					option_n(int *i, t_args *args, t_cv *env);
int					option_d(int *i, t_args *args, t_cv *env);
int					option_i(int *i, t_args *args, t_cv *env);
int					option_v(int *i, t_args *args, t_cv *env);

/*
** Filling data
*/
int					set_mempointer(t_cv *env);
int					complete_structures(t_cv *env);
int					initiate_proc(t_cv *env);

/*
** Chained list for the process queue
*/
t_proc				*create_list(void);
void				add_process(t_proc **begin_node);
void				push_process(t_proc **begin_node);
void				kill_process(t_proc **process, unsigned id);

/*
** Reading in the memory
*/
uint8_t				read_8(t_cv *env, unsigned n);
uint16_t			read_16(t_cv *env, unsigned n);
uint32_t			read_32(t_cv *env, unsigned n);

/*
** Writing in the memory
*/
void				write_8(t_cv *env, unsigned n, uint8_t content, int p);
void				write_16(t_cv *env, unsigned n, uint16_t content, int p);
void				write_32(t_cv *env, unsigned n, uint32_t content, int p);

/*
** Operation jump table and the cost associated with it
*/
t_op				*get_op(void);
unsigned			*get_cost(void);

/*
** Laumch the vm
*/
int					run(t_cv *env);

/*
** Things for the ui
*/
unsigned			get_proc_count(t_vm vm);
void				complete_colors(t_cv *env);
int					dump(t_cv *env);

/*
** Things for printing data
*/
int					print_cycle(t_cv *env);
int					print_ctd(t_cv *env);

/*
** Things for the ops
*/
void				shift_ocp(t_ocp *ocp, unsigned n_param);
int					is_cycle_to_die(t_vm *vm);
void				kill_not_alive(t_proc **queue);
int					check_reg_range(unsigned param);

/*
** The data setters
*/
int					set_reg_value(unsigned *param, t_cv *env, t_proc *proc,
									unsigned *pc);
int					set_reg_number(unsigned *param, t_cv *env, t_proc *proc,
									unsigned *pc);
int					set_dir_2(unsigned *param, t_cv *env, t_proc *proc,
								unsigned *pc);
int					set_dir_4(unsigned *param, t_cv *env, t_proc *proc,
								unsigned *pc);
int					set_ind(unsigned *param, t_cv *env, t_proc *proc,
								unsigned *pc);
int					set_lind(unsigned *param, t_cv *env, t_proc *proc,
								unsigned *pc);
int					nothing(unsigned *param, t_cv *env, t_proc *proc,
								unsigned *pc);
#endif
