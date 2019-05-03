.PHONY: clean, fclean, re

NAME = ../dygouasd.filler
EXEC_LIBFT = ../libft/libft.a
SRCS = filler.c fill_uti1.c filler_go.c fill_data.c
LIBDIR = ../libft/
CFLAGS = -Wall -Wextra -Werror
LIBS = -lft

SRCFILE = $(addprefix sources/, $(SRCS))
OBJS = $(SRCFILE:.c=.o)

all: $(NAME)

$(EXEC_LIBFT):
	make -C $(LIBDIR)
$(NAME): $(EXEC_LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $^ -L $(LIBDIR) $(LIBS) -o $(NAME)
%.o: %.c
	$(CC) -c $(CFLAGS) -I./includes $< -o $@
clean:
	make -C $(LIBDIR) clean
	$(RM) $(OBJS)
fclean: clean
	make -C $(LIBDIR) fclean
	$(RM) $(NAME)
re: fclean all
