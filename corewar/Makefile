# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/15 21:12:37 by afrangio          #+#    #+#              #
#    Updated: 2019/03/16 14:15:15 by afrangio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = corewar

all: $(NAME)

$(NAME): libft asm vm dasm

re: fclean all

fclean:
	make -C assembly/ fclean
	make -C vm/ fclean

clean:
	make -C assembly/ clean
	make -C vm/ clean

asm:
	make -C assembly/ asm

vm:
	make -C vm/

libft:
	make -C vm/libft
	make -C assembly/lib/libft

.PHONY: asm vm all fclean clean dasm

