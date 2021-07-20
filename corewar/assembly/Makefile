# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/15 21:09:07 by afrangio          #+#    #+#              #
#    Updated: 2019/03/15 21:12:03 by afrangio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###############################################################################
##                                                                           ##
##  This is a generalized makefiles made to be used on different kind        ##
##  of projects, such as making libraries , source files etc.                ##
##  Please note that to use this make files you need to posses the `.misc`   ##
##  directory that is included in the repo by default. This path is needed   ##
##  as some files used by make files are included there. Do change anything  ##
##  dependeing on your need.                                                 ##
##                                                                           ##
##  In the file `color` located in `.misc/make` you can find terminal escape ##
##  codes for colors arr or remove or eddid to get result as you want.       ##
##                                                                           ##
##                                                                           ##
##  In the file `path` located in `.misc/make` information about varius paths##
##  are included for to make this Makefile easier and to manage the make file##
##  More easily.                                                             ##
##                                                                           ##
###############################################################################


## Please do not remove the includes
## as they contain impoirtent information
## variables and rules

include .misc/make/color
include .misc/make/paths
include .misc/make/misc_var

## Te `.SILENT` launche evrything specified in
## silent mode so you dont have to put the `@`
.SILENT	: __START	NAME	clean fclean all re object library os_dep
.PHONY	: __START			clean fclean all re object library os_dep



## This is launched if no param given
.DEFAULT_GOAL = __START

## Project name (will be used)
PROJECT	=	COREWAR

## compiler related
CC		?=	clang 		## default compiler is clang

CC_FLAG ?=	-Werror \
			-Wall	\
			-Wextra


CC_FLAG_ASAN ?=	-Werror								\
				-Wall								\
				-Wextra								\
				-g -fsanitize=address				\
				-fno-omit-frame-pointer				\
				-fsanitize-address-use-after-scope	\

## some useful `flags` for memory verifications
##
## -O1 -g -fsanitize=address	\
	## -fno-omit-frame-pointer		\
	## -fsanitize-address-use-after-scope \


## binary, library etc...
MAIN	?=	main.c
NAME	?=	corewar 		## The name of your binary

COREWAR 		?=	corewar
P_COREWAR		?=	$(P_SRC)/core
COREWAR_MAIN	?=	corewar.c

ASM 			?=	asm
P_ASM			?=	$(P_SRC)/asm
ASM_MAIN		?=	asm.c

ifeq ($(MY_OS_NAME), Linux)
	NCURSES_ALERT ?= ""
	COREWAR_LINK	?=	 -lft -lftprintf -lncurses -lftprintferr
else
	#in 42 by default ncurses 5 is installed so we will use this specific link to uses ncurses 6 by brew
	NCURSES_ALERT ?= $(shell printf "$(WARN)[!][$(PROJECT)] USING ncurses from ~/.brew/opt/ncurses/[lib/|include] $(C_DEF)\n")
	COREWAR_LINK	?=	 -lft -lftprintf -lftprintferr  -L  ~/.brew/opt/ncurses/lib/ -lncurses -I ~/.brew/opt/ncurses/include/
endif


ASM		?=	asm

#The name of the library you want to make
LIB_A	?=	one.a

#All LIB_FT stufs
LIBFT		= $(P_LIB)/libft
LIBFT_INC	= $(LIBFT)/include
LIBFT_LIB	= $(LIBFT)/lib
LIBFT_A		= $(LIBFT_LIB)/libft.a
FT_PRINTF_A	= $(LIBFT_LIB)/libftprintf.a
FT_PRINTF_ERR_A	= $(LIBFT_LIB)/libftprintferr.a

## sources and objects where path names are removed.
## Add all your source files to this variable
SRC_ASM		=	$(P_ASM)/$(ASM_MAIN)				\
				$(P_ASM)/lexobj_print_tree.c		\
				$(P_ASM)/ft_strsplitn.c				\
				$(P_ASM)/ft_strdupn.c				\
				$(P_ASM)/sfile/sfile_read.c			\
				$(P_ASM)/sfile/sfile_init.c			\
				$(P_ASM)/sfile/sfile_stat.c			\
				$(P_ASM)/sfile/sfile_close.c		\
				$(P_ASM)/sfile/sfile_new.c			\
				$(P_ASM)/tab_replace.c				\
				$(P_ASM)/free_tab.c					\
				$(P_ASM)/is_space.c					\
				$(P_ASM)/ft_atol.c					\
				$(P_ASM)/ft_static_itoa.c			\
				$(P_ASM)/str_is_numer.c				\
				$(P_ASM)/is_labelchar.c				\
				$(P_ASM)/str_is_label_char.c		\
				$(P_ASM)/init_asm.c					\
				$(P_ASM)/init_asm2.c				\
				$(P_ASM)/free_asm.c					\
				$(P_ASM)/free_fname.c				\
				$(P_ASM)/free_arg_name.c			\
				$(P_ASM)/free_file_q.c				\
				$(P_ASM)/push_name.c				\
				$(P_ASM)/push_arg_name.c			\
				$(P_ASM)/push_file_q.c				\
				$(P_ASM)/qeue_file.c				\
				$(P_ASM)/get_argv.c					\
				$(P_ASM)/get_argv2.c				\
				$(P_ASM)/lex/free_lexobj.c			\
				$(P_ASM)/lex/clear_lexchain.c		\
				$(P_ASM)/lex/lexobj_push.c			\
				$(P_ASM)/lex/lexobj_new.c			\
				$(P_ASM)/lex/check_lexobj_tree.c	\
				$(P_ASM)/lex/is_lex_spearator.c		\
				$(P_ASM)/lex/is_register.c			\
				$(P_ASM)/lex/is_instruction.c		\
				$(P_ASM)/lex/is_indirect.c			\
				$(P_ASM)/lex/is_label.c				\
				$(P_ASM)/lex/lexobj_push_line.c		\
				$(P_ASM)/lex/asm_lex.c				\
				$(P_ASM)/lex/lex_comment.c			\
				$(P_ASM)/lex/lex_separator.c		\
				$(P_ASM)/lex/lex_indirect.c			\
				$(P_ASM)/lex/lex_header_meta.c		\
				$(P_ASM)/lex/lex_string.c			\
				$(P_ASM)/lex/lex_label_call.c		\
				$(P_ASM)/lex/lex_register.c			\
				$(P_ASM)/lex/lex_instruction.c		\
				$(P_ASM)/lex/lex_direct.c			\
				$(P_ASM)/lex/lex_label.c			\
				$(P_ASM)/lex/lex_unknown.c			\
				$(P_ASM)/pars/pars_error.c			\
				$(P_ASM)/pars/count_lexobj.c		\
				$(P_ASM)/pars/string_join.c			\
				$(P_ASM)/pars/get_string_pars.c		\
				$(P_ASM)/pars/get_next_lexobj.c		\
				$(P_ASM)/pars/free_pars.c			\
				$(P_ASM)/pars/pars_new.c			\
				$(P_ASM)/pars/pars_new2.c			\
				$(P_ASM)/pars/get_label_by_name.c	\
				$(P_ASM)/pars/get_inst_by_name.c	\
				$(P_ASM)/pars/pars_header.c			\
				$(P_ASM)/pars/pars_name.c			\
				$(P_ASM)/pars/pars_comment.c		\
				$(P_ASM)/pars/param_len_verify.c	\
				$(P_ASM)/pars/verify_param_type.c	\
				$(P_ASM)/pars/verify_param_type2.c	\
				$(P_ASM)/pars/set_param.c			\
				$(P_ASM)/pars/verify_register.c		\
				$(P_ASM)/pars/verify_int_indirect.c	\
				$(P_ASM)/pars/verify_int_direct.c	\
				$(P_ASM)/pars/set_inst.c			\
				$(P_ASM)/pars/pars_instruction.c	\
				$(P_ASM)/pars/pars_lexobj.c			\
				$(P_ASM)/bin/pars_to_binary.c		\
				$(P_ASM)/bin/write_binary.c			\

## Objects without path names
OBJ		:=	$(notdir $(SRC:.c=.o))

## Objects with their path name
OBJ_P	=	$(addprefix $(P_OBJ)/,$(OBJ))	## addprefix add the
## path name to the files...


## Start making here
__START: all
	printf "$(OK)[+][$(PROJECT)] Done$(C_DEF)\n"

## For multiple Binarys
all : $(LIBFT_A) $(FT_PRINTF_A) $(ASM)
	# @make $(COREWAR) --no-print-directory
	# Put assembler here

$(ASM): $(LIBFT_A) $(FT_PRINTF_A) $(SRC_ASM) $(P_INCLUDE)/$(ASM).h $(FT_PRINTF_ERR_A)
	@$(CC) $(CC_FLAG) $(SRC_ASM) -I $(P_INCLUDE) -I $(LIBFT_INC) -L $(LIBFT_LIB) -lft -lftprintf -lftprintferr -o $(ASM)
	@printf "$(OK)[+][$(PROJECT)] Made $(ASM)$(C_DEF)\n"


$(LIBFT_A):
	@make -C $(LIBFT) --no-print-directory

$(FT_PRINTF_A):
	@make -C $(LIBFT) ft_printf --no-print-directory

$(FT_PRINTF_ERR_A):
	@make -C $(LIBFT) ft_printf_err --no-print-directory

## Clean objects and others
clean:		$(OBJ_P)
	make	-C $(LIBFT) clean --no-print-directory
	@printf	"$(WARN)[!][$(PROJECT)] Removed all objects from ./$(P_OBJ)$(C_DEF)\n"
	@printf	"$(OK)[+][$(PROJECT)] Cleaned$(C_DEF)\n"

## Cleans everything
fclean:		clean
	make	-C $(LIBFT) fclean --no-print-directory
	rm		-f $(ASM)
	@printf	"$(WARN)[!][$(PROJECT)] Removed all binary ./$(P_BIN)$(C_DEF)\n"
	@printf	"$(OK)[+][$(PROJECT)] Fully cleaned$(C_DEF)\n"

re:			fclean all

## This function creat object files from sources.
## It treates the string of large source names as
## individual names, when it creat objects it do
## not gives al the names in the same time to gcc
## but one by one.
object:		$(SRC) $(P_SRC) $(P_OBJ)
	$(foreach SOURCE, $(SRC), \
		$(CC) $(CC_FLAG) -I$(P_INCLUDE) -c $(SOURCE) -o $(P_OBJ)/$(notdir $(SOURCE:.c=.o))	&& \
		printf "$(OK)[+][$(PROJECT)] $(SOURCE)$(C_DEF)" && sleep $(SLEEP)	&& \
		printf "\r\033[K" \
		;)
	printf "$(OK)[+][$(PROJECT)] Objects are made in ./$(P_OBJ)$(C_DEF)\n"

## Make the actual library (archive)
library:	object $(P_OBJ) $(OBJ_P)
	printf "$(WARN)[!][$(PROJECT)] Creating archive $(LIB_A)$(C_DEF)\n"
	@ar rc $(LIB_A) $(OBJ_P)
	printf "$(WARN)[!][$(PROJECT)] Generating index in $(LIB_A)$(C_DEF)\n"
	@ranlib $(LIB_A)
	printf "$(OK)[+][$(PROJECT)] The $(LIB_A) library was made$(C_DEF)\n"



## This rule is called when a difference in operating sistem has been
## detected. You can put your prerequisite to be changed if a different
## os has been detected
os_dep: #put your prerequisite for os dependent stufs
	## put your os dependent comands here
	## this will be launched if the os name is
	## different then what read from the os file.
	## ex: make re
	printf "[$(PROJECT)] Os dependent stufs\n"

## Useful Makefile tricks
##
## ?= 			// let you put a default variable then later change it
## j<number>	// let you launche the number of job at the same time
## ifdef		// let you verify if used defined something or not
## .SILENT		// This parameter let you launch rules in silent mod
## .IGNORE		// Ignore parameter used as .SILENT
#
## --stop-on-faliur			// stop the program if error occures
## -k or --keep-going		// To keep ignoring all errors
## -i or --ignore-errors	// To Ignor error
## --no-print-directory		// This do not show the 'entered ... directory' warning
