# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 01:50:24 by afrangio          #+#    #+#              #
#    Updated: 2019/03/16 16:16:45 by afrangio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	corewar
CC				=	cc


CFLAGS			:=	-Wall  \
					-Werror \
					-Wextra

NOSCOPE			=	-g -std=c89 \
					-Weverything \
					-Wno-padded \
					-fsanitize=address	\
					-fno-omit-frame-pointer		\
					-fsanitize-address-use-after-scope


SOURCES			=	srcs/main.c \
					srcs/ncurse/ncurses_write.c \
					srcs/ncurse/ncurses_uti.c \
					srcs/ncurse/window_print.c \
					srcs/op/add.c \
					srcs/op/aff.c \
					srcs/op/and.c \
					srcs/op/fork.c \
					srcs/op/ld.c \
					srcs/op/ldi.c \
					srcs/op/lfork.c \
					srcs/op/live.c \
					srcs/op/lld.c \
					srcs/op/lldi.c \
					srcs/op/or.c \
					srcs/op/st.c \
					srcs/op/sti.c \
					srcs/op/sub.c \
					srcs/op/xor.c \
					srcs/op/zjmp.c \
					srcs/parsing/arguments_parser.c \
					srcs/parsing/complete_colors.c \
					srcs/parsing/complete_structures.c \
					srcs/parsing/error_handler.c \
					srcs/parsing/messages/error_messages_1.c \
					srcs/parsing/messages/error_messages_2.c \
					srcs/parsing/messages/show_usage.c \
					srcs/parsing/options/option_d.c \
					srcs/parsing/options/option_i.c \
					srcs/parsing/options/option_v.c \
					srcs/parsing/options/options_n.c \
					srcs/parsing/parsing_cor.c \
					srcs/parsing/set_mempointer.c \
					srcs/parsing/warrior.c \
					srcs/utility/get.c \
					srcs/utility/memory/dump.c \
					srcs/utility/memory/read.c \
					srcs/utility/memory/write.c \
					srcs/utility/node.c \
					srcs/vm/initiate_proc.c \
					srcs/vm/messages.c \
					srcs/vm/run.c \
					srcs/vm/set_params/set_dir.c \
					srcs/vm/set_params/set_ind.c \
					srcs/vm/set_params/set_params.c \
					srcs/vm/set_params/set_reg.c \
					srcs/vm/vm_utils.c


INCLUDES		=	includes/colors.h \
					includes/corewar.h \
					includes/error_handling.h \
					includes/graphical_interface.h \
					includes/op.h \
					includes/types.h \
					includes/vm.h

SRCS 			=	$(SOURCES) #$(addprefix srcs/, $(SOURCES))

LIBS			=	-lncurses

all: $(NAME)

$(NAME): $(SRCS) libft/libft.a 
	$(CC) $(SRCS) -I libft/includes -L libft -lft -I includes  $(CFLAGS) $(LIBS) -o $(NAME)


noscope: CFLAGS += $(NOSCOPE) 
noscope: all


libft/libft.a:
	@make -C libft/

clean:
	@make -C libft/ clean

fclean: clean
	@make -C libft/ fclean
	@/bin/rm -f $(NAME)

re: fclean all
