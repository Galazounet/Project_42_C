.PHONY: clean, fclean, re
.SUFFIXES: .c .o .h .a
LIBFT_DIR = ./libft/
EXEC_LIBFT = libft/libft.a
VISUAL_DIR = visual/
FILLER_DIR = filler/
EXEC = $(VISUAL_DIR)/visual
EXEC = dygouasd.filler
INCDIR = inc/
LIBS =  -lft -lncurses
FRAMEWORKSDIR = $(HOME)/Library/Frameworks/

all: $(EXEC_LIBFT) $(EXEC)

$(EXEC_LIBFT):
		make -C $(LIBFT_DIR)

$(EXEC):
		make -C $(VISUAL_DIR)
		make -C $(FILLER_DIR)
clean:
	make -C $(LIBFT_DIR) clean
	make -C $(VISUAL_DIR) clean
	make -C $(FILLER_DIR) clean
fclean:
	make -C $(LIBFT_DIR) fclean
	make -C $(VISUAL_DIR) fclean
	make -C $(FILLER_DIR) fclean
re: fclean all
