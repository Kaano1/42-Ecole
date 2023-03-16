SRCS = main.c check_map.c \
	utils/get_line.c utils/is_space.c utils/add_NSWE.c\
	utils/clear_map_exit.c utils/add_Pixel.c utils/freeArray.c
OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = #-Wall -Wextra -Werror

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