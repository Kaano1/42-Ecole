SRCS = main.c check_map.c

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = #-Wall -Wextra -Werror

NAME = GAME

MANAGE = manage.a

RM = rm -rf

all: $(NAME)

$(NAME): first $(OBJS)
	$(CC) $(OBJS) $(MANAGE) -o $(NAME)
	

first:
	make -C ./help

clean:
	$(RM) $(OBJS)
	make fclean -C ./help

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean re