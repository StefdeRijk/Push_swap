NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror
COMPILE = $(CC) $(CFLAGS)
ARCHIVE = ./Libft/libft.a
ARCHIVE_DIR = ./Libft

FILES =	ft_push_swap.c\
		ft_swap.c\
		ft_push.c\
		ft_rotate.c\
		ft_reverse.c\
		ft_delete.c\
		three_long.c\
		five_long.c\

OBJS = $(FILES:.c=.o)

$(NAME): libft $(OBJS)
	@$(COMPILE) $(ARCHIVE) -I $(ARCHIVE_DIR) $(OBJS) -o $(NAME)
	@echo "Creating executable file"

all: libft $(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "Removing object files"
	@$(MAKE) clean -C ./Libft

fclean: clean
	@rm -f $(NAME)
	@echo "Removing executable file"
	@$(MAKE) fclean -C ./Libft/

libft:
	@$(MAKE) -C ./Libft/ bonus

re: fclean | all

.PHONY: all clean fclean re libft