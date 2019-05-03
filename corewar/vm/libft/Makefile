# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afrangio <afrangio@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/21 02:00:39 by afrangio          #+#    #+#              #
#    Updated: 2019/03/16 15:58:37 by afrangio         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
NAME		= libft.a
CFILES		= 	srcs/io/ft_putchar.c\
 				srcs/io/ft_putchar_fd.c\
 				srcs/io/ft_putendl.c\
				srcs/io/ft_putendl_fd.c\
				srcs/io/ft_putstrlen_fd.c\
				srcs/io/ft_putstrlen.c\
				srcs/io/ft_putnbr.c\
				srcs/io/ft_putnbr_fd.c\
				srcs/io/ft_putstr.c\
				srcs/io/ft_putstr_fd.c\
				srcs/io/ft_putwchar.c\
				srcs/io/ft_putwchar_fd.c\
				srcs/io/get_next_line.c\
				srcs/maths/ft_log.c\
				srcs/maths/ft_max.c\
				srcs/maths/ft_min.c\
				srcs/maths/ft_pow.c\
				srcs/maths/ft_ulog.c\
				srcs/mem/ft_bzero.c\
				srcs/mem/ft_memalloc.c\
				srcs/mem/ft_memccpy.c\
				srcs/mem/ft_memchr.c\
				srcs/mem/ft_memcmp.c\
				srcs/mem/ft_memcpy.c\
				srcs/mem/ft_memdel.c\
				srcs/mem/ft_memmove.c\
				srcs/mem/ft_memset.c\
				srcs/mem/ft_realloc.c\
				srcs/mem/ft_swap.c\
				srcs/string/check/ft_isalnum.c\
				srcs/string/check/ft_isalpha.c\
				srcs/string/check/ft_isascii.c\
				srcs/string/check/ft_isdigit.c\
				srcs/string/check/ft_isprint.c\
				srcs/string/check/ft_isspace.c\
				srcs/string/check/ft_isnumber.c\
				srcs/string/comparaisons/ft_strcmp.c\
				srcs/string/comparaisons/ft_strequ.c\
				srcs/string/comparaisons/ft_strncmp.c\
				srcs/string/comparaisons/ft_strnequ.c\
				srcs/string/comparaisons/ft_strstr.c\
				srcs/string/conversions/ft_atoi.c\
				srcs/string/conversions/ft_itoa.c\
				srcs/string/conversions/ft_itoa_base.c\
				srcs/string/search/ft_strcat.c\
				srcs/string/search/ft_strchr.c\
				srcs/string/search/ft_strlcat.c\
				srcs/string/search/ft_strncat.c\
				srcs/string/search/ft_strnstr.c\
				srcs/string/search/ft_indexof.c\
				srcs/string/ft_strclr.c\
				srcs/string/ft_strcpy.c\
				srcs/string/ft_strdel.c\
				srcs/string/ft_strdup.c\
				srcs/string/ft_striter.c\
				srcs/string/ft_striteri.c\
				srcs/string/ft_strjoin.c\
				srcs/string/ft_strlen.c\
				srcs/string/ft_strmap.c\
				srcs/string/ft_strmapi.c\
				srcs/string/ft_strncpy.c\
				srcs/string/ft_strnew.c\
				srcs/string/ft_strrchr.c\
				srcs/string/ft_strsplit.c\
				srcs/string/ft_strsub.c\
				srcs/string/ft_strtrim.c\
				srcs/string/ft_tolower.c\
				srcs/string/ft_toupper.c

OBJ			=   $(notdir $(CFILES:.c=.o)) 

INCLUDES		=	includes/get_next_line.h\
					includes/ioft.h\
					includes/libft.h\
					includes/mathsft.h\
					includes/memft.h\
					includes/stringft.h


all: $(NAME)

$(NAME): $(CFILES)
	$(CC) $(CFILES) -c $(CFLAGS) -Iincludes 
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

ret: fclean test
