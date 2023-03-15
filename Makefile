SRCS = main.c check_map.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

NAME = GAME

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	

clean:
	$(RM) $(OBJS)
	make clean -C ./help

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean re