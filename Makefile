NAME = push_swap

FLAGS = -Wall -Werror -Wextra

CC = gcc

OBJS = $(FILES:.c=.o)

FILES =	ft_push_swap.c\
		ft_swap.c\
		ft_push.c\

%.o : %.c
		@$(CC) $(FLAGS) -c $<
		@echo "Compiling $<"

$(NAME): $(OBJS)
	@$(MAKE) bonus -C ./Libft
	@echo "Compiling library"
	@ar -cr $(NAME) $(OBJS)
	@echo "Creating archive file"

all: $(NAME)
	chmod 700 push_swap

clean:
	@rm -rf $(OBJS)
	@echo "Removing object files"
	@$(MAKE) clean -C ./Libft

fclean: clean
	@rm -f $(NAME)
	@echo "Removing archive file"
	@$(MAKE) fclean -C ./Libft

re: fclean | all

.PHONY: all clean fclean re test