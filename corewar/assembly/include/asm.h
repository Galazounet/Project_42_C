/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 12:09:22 by suddin            #+#    #+#             */
/*   Updated: 2019/03/15 21:30:14 by afrangio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ASM_H
# define FT_ASM_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <sys/stat.h>
# include <limits.h>
# include <errno.h>
# include <dirent.h>
# include "libft.h"
# include "ft_printf.h"
# include "ft_printf_err.h"

# define SUCCESS										0
# define ERROR				-							1
# define WARNING										2

# define MAX_FILE_SIZE									200000
# define ASM_MAX_BUFF_SIZE								2048
# define TYPE_DIR 										0b00000001
# define TYPE_REG 										0b00000010
# define ASM_MAX_DATA_SIZE								4096
# define ASM_DATA_ADD_FACT								3
# define STATUS_GOOD									0
# define STATUS_BAD										1
# define ASM_UNKNOWN									0
# define ASM_COMMENT 									1
# define ASM_HEADER_META								2
# define ASM_STRING										3
# define ASM_LABEL										4
# define ASM_INSTRUCTION								5
# define ASM_REGISTER									6
# define ASM_DIRECT										7
# define ASM_INDIRECT									8
# define ASM_SEPARATOR									9
# define ASM_STRING_START								1
# define ASM_STRING_END									11
# define ASM_LEBEL_CALL									12
# define ASM_LEBEL_DIRECT								13
# define ASM_LEBEL_INDIRECT								14
# define NAME_STRING									".name"
# define COMMENT_STRING									".comment"
# define COMMENT_CHAR_1									'#'
# define COMMENT_CHAR_2									';'
# define SEPARATOR_CHAR									','
# define DIRECT_CHAR									'%'
# define STRING_CHAR									'"'
# define HEADER_META_CHAR								'.'
# define LEBEL_LIMIT_CHAR								':'
# define LEX_ERR_LABEL_CHAR								1
# define LEX_ERR_NUMBER									2
# define LEX_ERR_UNKN_META								3
# define LEX_ERR_EMPTY_LABEL							4
# define LEX_ERR_UNKN_TYPE								5
# define LEX_ERR_NO_NUM_SUGN							6
# define LEX_ERR_LABEL_CALL_CHAR						7
# define DI												0b00000001
# define IN												0b00000010
# define RE												0b00000100
# define ARG_TYPE_LABEL									1
# define ARG_TYPE_DIRECT								2
# define ARG_TYPE_INDIRECT								3
# define ARG_TYPE_REGISTER								4
# define SIZE_REGISTER									1
# define SIZE_INDIRECT									2
# define SIZE_DIRECT									4
# define ENCODED_REGISTER								0b00000001
# define ENCODED_DIRECT									0b00000010
# define ENCODED_INDIRECT								0b00000011
# define INST_NB_LIVE									1
# define INST_NB_LD										2
# define INST_NB_ST										3
# define INST_NB_ADD									4
# define INST_NB_SUB									5
# define INST_NB_AND									6
# define INST_NB_OR										7
# define INST_NB_XOR									8
# define INST_NB_ZJMP									9
# define INST_NB_LDI									10
# define INST_NB_STI									11
# define INST_NB_FORK									12
# define INST_NB_LLD									13
# define INST_NB_LLDI									14
# define INST_NB_LFORK									15
# define INST_NB_AFF									16
# define INST_INDEX_MAX									16
# define INST_INDEX_LIVE								0
# define INST_INDEX_LD									1
# define INST_INDEX_ST									2
# define INST_INDEX_ADD									3
# define INST_INDEX_SUB									4
# define INST_INDEX_AND									5
# define INST_INDEX_OR									6
# define INST_INDEX_XOR									7
# define INST_INDEX_ZJMP								8
# define INST_INDEX_LDI									9
# define INST_INDEX_STI									10
# define INST_INDEX_FORK								11
# define INST_INDEX_LLD									12
# define INST_INDEX_LLDI								13
# define INST_INDEX_LFORK								14
# define INST_INDEX_AFF									15
# define FLAG_O											0b00000001
# define FLAG_STRICT									0b00000010
# define FLAG_H											0b00000100
# define FLAG_Q											0b00001000
# define FLAG_NAME_O									"-o"
# define FLAG_NAME_H									"-h"
# define FLAG_NAME_Q									"-q"
# define FLAG_NAME_S									"-s"
# define FLAG_NAME_OUTPUT								"--output"
# define FLAG_NAME_STRICT								"--strict"
# define FLAG_NAME_HELP									"--help"
# define FLAG_NAME_QUIET								"--quiet"
# define INST_MAX_PARAM									7
# define INS_PARAM1										0
# define INS_SEPARATOR1									1
# define INS_PARAM2										2
# define INS_SEPARATOR2									3
# define INS_PARAM3										4
# define INS_SEPARATOR									5
# define INS_PARAM4										6
# define NAME_SIZE										128
# define COMMENT_SIZE									2048
# define MAGIC_NUMBER_SIZE								4
# define INST_SECTION_SIZE								4
# define MAGIC_NUMBER									0xea83f3
# define STR_LINE										0
# define STR_INDEX										1
# define HEADER_LEN										2184

typedef struct		s_lexobj
{
	int				line;
	int				start_index;
	int				type;
	char			*value;
	int				status;
	int				error;
	struct s_lexobj	*next_obj;
	struct s_lexobj	*next_line;
}					t_lexobj;

typedef struct		s_sfile
{
	char			*file_name;
	char			*file_name_cor;
	char			*path_name;
	int				file_type;
	int				file_fd;
	size_t			file_size;
	struct stat		st;
	char			**tab;
	struct s_sfile	*next;
}					t_sfile;

typedef struct		s_instruction
{
	uint8_t			inst;
	uint8_t			encoded;
	uint32_t		mem_index;
	int32_t			arg[4];
	uint8_t			arg_type[4];
	uint32_t		arg_size[4];
	uint32_t		total_inst_size;
}					t_inst;

typedef struct		s_pars
{
	char			*name;
	int				name_len;
	char			*comment;
	int				comment_len;
	int				inst_section_len;
	char			**label_name;
	int				label_max;
	int				*label_tab;
	t_inst			*inst_table;
	int				inst_count;
	int				inst_max;
	int				tmp_param_nb;
	int				tmp_param_count;
	int				tmp_param_curr;
	uint8_t			*bin;
	int				bin_len;
}					t_pars;

typedef struct		s_fname
{
	char			*name;
	struct s_fname	*next;
}					t_fname;

typedef struct		s_instruction_meta_data
{
	char			name[7];
	int				max_param;
	int				param_type[4];
	int				direct_size;
	int				encoded;
}					t_inst_meta;

typedef struct		s_asm
{
	int				flag;
	t_sfile			*curr_file;
	t_lexobj		*curr_lex;
	int				file_q_len;
	t_sfile			*file_q;
	int				fname_len;
	t_fname			*fname;
	t_fname			*arg_name;
	int				arg_name_len;
	t_inst_meta		inst_meta[16];
}					t_asm;

char				**ft_strsplitn(char const *s, char c);
char				*ft_strdupn(char *str, size_t n);
void				tab_replace(char **tab, int chr, int rep);
void				free_tab(char **tab);
int					is_space(char c);
int					str_is_numer(char *str);
int					is_labelchar(char c);
int					str_is_label_char(char *str);
int					ft_atol(char *str);
char				*ft_static_itoa(int n);
void				init_asm(t_asm *asmb);
void				free_asm(t_asm *asmb);
void				free_fname(t_asm *asmb);
void				free_arg_name(t_asm *asmb);
void				free_file_q(t_asm *asmb);
void				push_name(t_asm *asmb, char *name);
void				push_arg_name(t_asm *asmb, char *name);
int					get_argv(t_asm *asmb, int argc, char **argv);
char				**sfile_read(t_sfile *file);
void				sfile_init(t_sfile *file);
void				sfile_close(t_sfile *file);
int					sfile_stat(char *fname, t_sfile *file);
t_sfile				*sfile_new(void);
void				push_file_q(t_asm *asmb, t_sfile *file);
int					qeue_file(t_asm *asmb);
void				clear_lexchain(t_lexobj **lex);
void				lexobj_push(t_lexobj **mother, t_lexobj *child);
void				lexobj_push_line(t_lexobj *tree, t_lexobj *lex);
t_lexobj			*lexobj_new(unsigned int line, int index, int type);
void				free_lexobj(t_lexobj **lex);
int					is_lex_spearator(char c);
int					is_register(char *str);
int					is_instruction(char *str);
int					is_indirect(char *str);
int					is_label(char *str);
int					check_lexobj_tree(t_asm *asmb, t_lexobj *tree);
t_lexobj			*asm_lex(char **tab, unsigned int line, int string_on,
		t_lexobj *tree);
int					lex_comment(char *str);
int					lex_separator(char *str, t_lexobj **moth,
		unsigned int line, int index);
int					lex_direct(char *str, t_lexobj **moth, unsigned int line,
		int index);
int					lex_header_meta(char *str, t_lexobj **moth,
		unsigned int line, int index);
int					lex_string(char *str, t_lexobj **moth, int *lx_str,
		int *strin_end);
int					lex_label_call(char *str, t_lexobj **moth,
		unsigned int line, int index);
int					lex_register(char *str, t_lexobj **moth,
		unsigned int line, int index);
int					lex_instruction(char *str, t_lexobj **moth,
		unsigned int line, int index);
int					lex_indirect(char *str, t_lexobj **moth,
		unsigned int line, int index);
int					lex_label(char *str, t_lexobj **moth,
		unsigned int line, int index);
int					lex_unknown(char *str, t_lexobj **moth,
		unsigned int line, int index);
int					pars_error(t_asm *asmb, char *msg, t_lexobj *lex,
		int err_n);
int					count_lexobj(t_lexobj *lex);
void				string_join(char **dest, char *src, int src_len);
char				*get_string_pars(char **tab, t_lexobj *start,
		t_lexobj *end);
t_lexobj			*get_next_lexobj(t_lexobj *lex);
void				free_pars(t_pars **pars);
t_pars				*pars_new(t_lexobj *lex);
int					get_label_by_name(t_pars *pars, char *label);
int					get_inst_by_name(char *inst);
int					param_len_verify(t_asm *asmb, t_lexobj *lex,
		t_inst_meta *meta);
t_lexobj			**verify_param_type(t_asm *asmb, t_lexobj *lex,
		t_inst_meta *meta);
int					set_param(t_asm *asmb, t_lexobj **param, t_pars *pars,
		t_inst *inst);
int					verify_register(t_asm *asmb, t_lexobj *lex, char *str);
int					verify_int_indirect(t_asm *asmb, t_lexobj *lex,
		char *value);
int					verify_int_direct(t_asm *asmb, t_lexobj *lex,
		char *value);
int					set_inst(t_asm *asmb, t_lexobj *lex, t_pars *pars,
		t_inst *inst);
t_pars				*pars_lexobj(t_asm *asmb, char **tab, t_lexobj *lex);
int					pars_header(t_asm *asmb, char **tab, t_lexobj **lex,
		t_pars *pars);
int					pars_name(t_asm *asmb, char **tab, t_lexobj **lex,
		t_pars *pars);
int					pars_comment(t_asm *asmb, char **tab, t_lexobj **lex,
		t_pars *pars);
int					pars_instruction(t_asm *asmb, t_lexobj *lex, t_pars *pars);
int					pars_to_binary(t_asm *asmb, t_pars *pars);
void				write_binary(t_asm *asmb, t_pars *pars);
void				lexobj_print_tree(t_lexobj *tree);

#endif
