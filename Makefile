NAME = push_swap

FLAGS = -Wall -Werror -Wextra

CC = gcc

OBJS = $(FILES:.c=.o)

FILES =	ft_push_swap.c\

%.o : %.c push_swap.h
		@$(CC) $(FLAGS) -c $<
		@echo "Compiling $<"

$(NAME): $(OBJS)
	@ar -cr $(NAME) $(OBJS)
	@echo "Creating archive file"

all: $(NAME)

clean:
	@rm -rf $(OBJS)
	@echo "Removing object files"

fclean: clean
	@rm -f $(NAME)
	@echo "Removing archive file"

re: fclean all

.PHONY: all clean fclean re