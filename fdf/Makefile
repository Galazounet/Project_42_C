.PHONY: clean, fclean, re

NAME = fdf
EXEC_LIBFT = ./libft/libft.a
SRCS = fdf_uti.c fdf_uti2.c main.c fdf_put_pixel.c
LIBDIR = ./libft/
CFLAGS = -Wall -Wextra -Werror
LIBS = -lft

SRCFILE = $(addprefix sources/, $(SRCS))
OBJS = $(SRCFILE:.c=.o)

all: $(NAME)

$(EXEC_LIBFT):
	make -C $(LIBDIR)
$(NAME): $(EXEC_LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $^ -L $(LIBDIR) $(LIBS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
%.o: %.c
	$(CC) -c $(CFLAGS) -I./includes $< -o $@
clean:
	make -C $(LIBDIR) clean
	$(RM) $(OBJS)
fclean: clean
	make -C $(LIBDIR) fclean
	$(RM) $(NAME)
re: fclean all
