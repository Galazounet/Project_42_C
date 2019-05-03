.PHONY: clean, fclean, re

NAME = fractol
EXEC_LIBFT = ./libft/libft.a
SRCS = main.c fract_uti1.c frac_uti2.c frac_julia.c frac_mandel.c \
	   frac_burn.c color.c frac_uti3.c
LIBDIR = ./libft/
CFLAGS = -Wall -Wextra -Werror
LIBS = -lft

SRCFILE = $(addprefix sources/, $(SRCS))
OBJS = $(SRCFILE:.c=.o)

all: $(NAME)

$(EXEC_LIBFT):
	make -C $(LIBDIR)
$(NAME): $(EXEC_LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $^ -L $(LIBDIR) $(LIBS) -lmlx -framework OpenGL -framework AppKit -lpthread -o $(NAME)
%.o: %.c
	$(CC) -c $(CFLAGS) -I./includes $< -o $@
clean:
	make -C $(LIBDIR) clean
	$(RM) $(OBJS)
fclean: clean
	make -C $(LIBDIR) fclean
	$(RM) $(NAME)
re: fclean all
