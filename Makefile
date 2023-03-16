SRCS = main.c \
	utils/is_space.c utils/clear_map_exit.c  utils/freeArray.c \
	parser/utils/add_Pixel.c parser/utils/add_NSWE.c parser/utils/get_line.c \
	parser/design_map.c parser/check_characters.c
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