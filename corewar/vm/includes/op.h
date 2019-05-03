/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 21:31:50 by afrangio          #+#    #+#             */
/*   Updated: 2019/01/25 21:32:50 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

# include "corewar.h"

/*
** op/live.c
*/
int					op_live(t_cv *env, t_proc *process);
int					op_aff(t_cv *env, t_proc *proc);
int					op_and(t_cv *env, t_proc *proc);
int					op_fork(t_cv *env, t_proc *proc);
int					op_ld(t_cv *env, t_proc *proc);
int					op_ldi(t_cv *env, t_proc *proc);
int					op_lfork(t_cv *env, t_proc *proc);
int					op_lld(t_cv *env, t_proc *proc);
int					op_lldi(t_cv *env, t_proc *proc);
int					op_or(t_cv *env, t_proc *proc);
int					op_st(t_cv *env, t_proc *proc);
int					op_sti(t_cv *env, t_proc *proc);
int					op_sub(t_cv *env, t_proc *proc);
int					op_xor(t_cv *env, t_proc *proc);
int					op_zjmp(t_cv *env, t_proc *proc);
int					op_add(t_cv *env, t_proc *proc);

#endif
