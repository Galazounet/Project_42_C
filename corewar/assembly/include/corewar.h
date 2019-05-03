/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 15:43:26 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 21:30:19 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_COREWAR_H
# define FT_COREWAR_H

# include "ft_printf_err.h"
# include <stdint.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <errno.h>
# include "libft.h"
# include "tui.h"
# include "ft_printf.h"

# define VM_MAX_INST_SIZE		(682)
# define VM_MEM_SIZE			(4*1024)
# define VM_PROG_NAME_LENGTH	(128)
# define VM_COMMENT_LENGTH		(2048)
# define VM_COREWAR_EXEC_MAGIC	0xea83f3
# define VM_MAX_ARGS_NUMBER		0x04
# define VM_REG_NUMBER			16
# define VM_MAX_PLAYERS			4
# define VM_CYCLE_TO_DIE		1536
# define VM_CYCLE_DELTA			50
# define VM_NBR_LIVE			21
# define VM_IDX_MOD				(VM_MEM_SIZE / 8)

# define VM_REG_SIZE			4
# define VM_REGISTER_SIZE		1
# define VM_IND_SIZE			2
# define VM_DIR_SIZE			VM_REG_SIZE
# define VM_WARR_ALIEV			1
# define VM_MAX_REG_NUMBER		VM_REG_NUMBER + 2

# define FLAG_T					0b00000001

# define VM_MAX_INST			0x11

# define INST_LIVE				0x00
# define INST_LD				0x01
# define INST_ST				0x02
# define INST_ADD				0x03
# define INST_SUB				0x04
# define INST_AND				0x05
# define INST_OR				0x06
# define INST_XOR				0x07
# define INST_ZJMP				0x08
# define INST_LDI				0x09
# define INST_STI				0x0a
# define INST_FORK				0x0b
# define INST_LLD				0x0c
# define INST_LLDI				0x0d
# define INST_LFORK				0x0e
# define INST_AFF				0x0f
# define INST_NOP				0x10

# define REG_PC					0x00
# define REG_R1					0x01
# define REG_R2					0x02
# define REG_R3					0x03
# define REG_R4					0x04
# define REG_R5					0x05
# define REG_R6					0x06
# define REG_R7					0x07
# define REG_R8					0x08
# define REG_R9					0x09
# define REG_R10				0x0a
# define REG_R11				0x0b
# define REG_R12				0x0c
# define REG_R13				0x0d
# define REG_R14				0x0e
# define REG_R15				0x0f
# define REG_R16				0x10
# define REG_CF					0x11

# define TYPE_REG				0b00000001
# define TYPE_DIR				0b00000010
# define TYPE_IND				0b00000011

# define SUCCESS				0
# define ERROR					-1

# define POS_X					0
# define POS_Y					1

# define BORDER_X				2
# define BORDER_Y				1

# define VM_MAX_READ_MEM		32

# define NORM_PROC_FLAG			0
# define SPEC_PROC_FLAG			1
# define FORK_PROC_FLAG			3

typedef unsigned char	t_uchar;
typedef unsigned short	t_ushort;
typedef unsigned int	t_uint;
typedef unsigned long	t_ulong;

typedef struct			s_vproc
{
	int					id;
	int32_t				reg[VM_MAX_REG_NUMBER];
	int32_t				reg_bf[VM_MAX_REG_NUMBER];
	int					inst;
	int					wait_cycle;
	int					live;
	uint32_t			load_addr;
	struct s_warrior	*warr;
	struct s_vproc		*next;
	struct s_vproc		*prev;
}						t_vproc;

typedef struct			s_warrior
{
	char				*file_name;
	int					warr_nb;
	int					serial;
	int					color_p;
	int					color_p_pc;
	uint8_t				name[VM_PROG_NAME_LENGTH + 1];
	uint8_t				comm[VM_COMMENT_LENGTH + 1];
	t_uint				warr_load_addr;
	uint8_t				inst[VM_MAX_INST_SIZE + 1];
	uint32_t			inst_len;
	t_vproc				*proc_start;
	uint8_t				*mem_share;
	int					*flag;
	WINDOW				**mem_win;
	WINDOW				**inf_win;
	int					*mem_change;
}						t_warrior;

typedef struct			s_corewar
{
	t_warrior			warr[VM_MAX_PLAYERS];
	t_uint				max_warr;
	int					cycle;
	int					max_cycle;
	int					cycle_to_die;
	int					live_warr_nb;
	int					live_count;
	uint8_t				memory[VM_MEM_SIZE];
	int					inst_cycle[VM_MAX_INST];
	int					proc_q_len;
	t_vproc				*proc_q;
	t_tui				tui;
	t_vproc				*proc_list[MAX_PROC_IN_LIST];
	int					proc_list_len;
	int					proc_list_pos;
	int					can_load_q;
	WINDOW				*mem_win;
	WINDOW				*inf_win;
	int					mem_change;
	int					pause;
	int					flag;
	int					dump;
	int					exec_stat;
	int					exec_speed;
	struct timespec		exec_wait_time;
	struct timespec		exec_set_time;
	int					(*(inst_func[VM_MAX_INST]))(struct	s_corewar *core, \
							t_warrior *warr, t_vproc *proc);
}						t_corewar;

void					init_core(t_corewar *cor);
int32_t					bytes_to_int(const uint8_t *num, unsigned num_len);
uint8_t					*int_to_bytes(uint32_t num, unsigned num_len);
int						init_tui(t_corewar *core);
int						is_reg_regular(int8_t reg);
int						ft_atol(char *str);
int						param_type(uint8_t encoded, int param_nb);
int						get_param_size(uint32_t param_type);
uint8_t					inst_id(uint8_t ins);
void					copy_register(int32_t *dest, int32_t *src);
void					show_winner(t_corewar *core);

void					set_pc(t_corewar *core, t_vproc *proc, \
							int32_t location, int flag);

void					shutdown_core(t_corewar *core);
int						load_warrior(t_corewar *core);

int						set_warr_file(t_corewar *core, char *file, int warr_nb);
int						check_number(char *str, int arg_nb);
int						get_dump(t_corewar *core, int argc, char **argv, int i);
int						get_n(t_corewar *core, int argc, char **argv, int i);
int						set_warr_nb(t_corewar *core);
int						get_arg(t_corewar *core, int argc, char **argv);

int						read_inst(t_warrior *warr, char *file, int fd);
int						read_comment(t_warrior *warr, char *file, int fd);
int						read_inst_size(t_warrior *warr, char *file, int fd);
int						read_name(t_warrior *warr, char *file, int fd);
int						read_magic(char *file, int fd);
int						read_file(t_corewar *core);

int						write_mem(t_warrior *warr, int location, uint8_t *src,\
							t_uint src_len);
uint8_t					*read_mem(t_corewar *core, int location);

int						inst_live(t_corewar *core, \
							t_warrior *warr, t_vproc *proc);
int						inst_ld(t_corewar *core, \
							t_warrior *warr, t_vproc *proc);
int						inst_st(t_corewar *core, \
							t_warrior *warr, t_vproc *proc);
int						inst_add(t_corewar *core, \
							t_warrior *warr, t_vproc *proc);
int						inst_sub(t_corewar *core, \
							t_warrior *warr, t_vproc *proc);
int						inst_and(t_corewar *core, \
							t_warrior *warr, t_vproc *proc);
int						inst_or(t_corewar *core, \
							t_warrior *warr, t_vproc *proc);
int						inst_xor(t_corewar *core, \
							t_warrior *warr, t_vproc *proc);
int						inst_zjmp(t_corewar *core, \
							t_warrior *warr, t_vproc *proc);
int						inst_ldi(t_corewar *core, \
							t_warrior *warr, t_vproc *proc);
int						inst_sti(t_corewar *core, \
							t_warrior *warr, t_vproc *proc);
int						inst_fork(t_corewar *core, \
							t_warrior *warr, t_vproc *proc);
int						inst_lld(t_corewar *core, \
							t_warrior *warr, t_vproc *proc);
int						inst_lldi(t_corewar *core, \
							t_warrior *warr, t_vproc *proc);
int						inst_lfork(t_corewar *core, \
							t_warrior *warr, t_vproc *proc);
int						inst_aff(t_corewar *core, \
							t_warrior *warr, t_vproc *proc);
int						ints_nop(t_corewar *core, \
							t_warrior *warr, t_vproc *proc);

t_vproc					*vproc_new(t_warrior *warr, uint32_t load_addr);
void					vproc_push(t_corewar *core, t_vproc *proc);

void					tui_write_mem_tog(t_warrior *warr, \
							t_uint location, uint8_t memory);
void					tui_write_mem_spe(t_warrior *warr, \
							t_uint location, uint8_t memory);
void					tui_write_mem_nor(t_warrior *warr, \
							t_uint location, uint8_t memory);

void					manage_mouse(t_corewar *core, int c);
void					manage_input(t_corewar *core, int c);
void					set_exec_speed(t_corewar *core, int percent);
void					exec_next(t_corewar *core);
int						togle_exec_stat(t_corewar *core);
void					clear_reg_val(WINDOW **regw);

void					update_cycle(t_corewar *core);
void					update_reg_val(WINDOW **regw, int32_t *reg);
void					update_proc_list(t_corewar *core);
void					update_cycle_to_die(t_corewar *core);
void					update_live(t_corewar *core);
void					update_proc_reg_info(t_corewar *core);
void					update_tui_cycle(t_corewar *core);
void					update_max_process(t_corewar *core);
void					tui_add_list(t_corewar *core);
char					*p_name(uint8_t *name);

void					exec_vproc_q(t_corewar *core);
void					set_delay(t_corewar *core);
int						check_delay(t_corewar *core);
void					exec_vproc_q_tui(t_corewar *core);
void					dump_mem(t_corewar *core);
int						cycle_to_die_check(t_corewar *core);
void					delete_proc(t_corewar *core, t_vproc *proc);
void					init_vproc_q(t_corewar *core, t_vproc *proc);
void					exec_vproc(t_corewar *core, t_vproc *proc);

#endif
