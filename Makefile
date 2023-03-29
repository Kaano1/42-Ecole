SRCS = main.c \
	utils/is_space.c utils/clear_map_exit.c  utils/free_array.c \
	parser/utils/add_pix.c parser/utils/add_NSWE.c parser/utils/get_line.c parser/utils/add_map.c \
	parser/utils/get_position.c \
	parser/design_map.c parser/check_characters.c parser/arrange_tMap.c \
	parser/get_data.c

OBJS = $(SRCS:.c=.o)

CC = gcc

FRAMEWORK = -lm -lXext -lX11

CFLAGS = -g #-Wall -Wextra -Werror

NAME = cub3D

MANAGE = manage.a minilibx/libmlx.a

RM = rm -rf

all: $(NAME)

$(NAME): first $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(MANAGE) $(FRAMEWORK) -o $(NAME)
	

first:
	make -C ./minilibx
	make -C ./help

clean:
	$(RM) $(OBJS)
	make fclean -C ./help
	make clean -C ./minilibx

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean clean re