SRC = push_swap.c command.c add_stack.c two_command.c \
		less5_solve.c check.c error.c radix.c pree.c check_arg.c \
			push_until.c
OBJ = $(SRC:.c=.o)
CC = gcc
RM = rm -rf
NAME = push_swap
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) -o $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all fclean clean re
