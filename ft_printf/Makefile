.PHONY: clean, fclean, re

NAME = libftprintf.a
EXEC_LIBFT = libft/libft.a
SRCS = ft_printf.c printf_conv.c printf_flag.c printf_conv_o.c printf_conv_d.c \
	   printf_conv_c.c printf_conv_i.c printf_conv_u.c printf_conv_p.c \
	   printf_conv_x.c printf_conv_percent.c printf_conv_s.c printf_all_flag.c \
	   printf_uti1.c printf_flag1.c printf_flag_champ_preci.c \
	   printf_print_flag.c printf_uti2.c printf_uti3.c printf_conv_noth.c \
	   printf_conv_b.c

SRCFILE = $(addprefix sources/, $(SRCS))
OBJS = $(SRCFILE:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)
%.o: %.c
	$(CC) -c $(CFLAGS) -I./includes $< -o $@
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
