.PHONY: clean, fclean, re

NAME = fillit
EXEC_LIBFT = libft/libft.a
SRCS = fillit.c fillresolv.c parser.c
OBJS = $(SRCS:.c=.o)
LIBDIR = libft/
CFLAGS = -Wall -Wextra -Werror
LIBS =  -lft

all: $(NAME)

$(EXEC_LIBFT):
	make -C $(LIBDIR)
$(NAME): $(EXEC_LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $^ -L $(LIBDIR)  $(LIBS) -o $(NAME)
%.o: %.c
	$(CC) -c $(CFLAGS) $< -I./ -I $(LIBDIR) -o $@
clean:
	make -C $(LIBDIR) clean
	$(RM) $(OBJS)
fclean: clean
	make -C $(LIBDIR) fclean
	$(RM) $(NAME)
re: fclean all
