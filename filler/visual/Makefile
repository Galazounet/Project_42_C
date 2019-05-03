.PHONY: clean, fclean, re
.SUFFIXES: .c .o .h .a
EXEC = visual
SRCS =	main.c sdl_getter.c sdl_event.c sdl_rect.c sdl_out.c sdl_render.c sdl_init.c sdl_init2.c sdl_clear.c  sdl_lib.c signal.c curs_print.c curs_init.c curs_getter.c curs_lib.c curs_del.c
OBJS = $(SRCS:.c=.o)
OBJDIR = obj/
SRCDIR = src/
LIBFT_DIR = ../libft/
EXEC_LIBFT = ../libft/libft.a
INCDIR = inc/
# CFLAGS = -Wall -Wextra -Werror
LIBS =  -lft -lncurses
VPATH = src/:inc/:obj/
FRAMEWORKSDIR = $(HOME)/Library/Frameworks/
all: $(EXEC_LIBFT) $(EXEC)

$(EXEC): $(OBJS)
	cc $(CFLAGS) $(addprefix $(OBJDIR), $(notdir $^)) -L../libft/ $(LIBS) -F $(FRAMEWORKSDIR) -framework SDL2 -framework SDL2_image -framework SDL2_ttf -o $(EXEC) -g
%.o: %.c
	cc -c $(CFLAGS) $< -I $(INCDIR) -I $(LIBDIR)/libft -I $(HOME)/.brew/include  -o $(addprefix $(OBJDIR), $@)
clean:
	$(RM) $(addprefix $(OBJDIR), $(OBJS))
fclean:
	$(RM) $(addprefix $(OBJDIR), $(OBJS))
	$(RM) $(EXEC)
re: fclean all
