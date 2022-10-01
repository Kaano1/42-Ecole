SRC =   so_long.c so_support.c read_key.c so_control.c so_control_ber.c\
			 add_map.c so_error.c so_free.c min/libmlx.a
OBJ =	$(SRC:.c=.o);
CC = gcc
M_FLAGS = -framework OpenGL -framework AppKit
C_FLAGS = -Wall -Wextra -Werror
RM = rm -rf
NAME = so_long
LIB = min/libmlx.a

all: $(LIB) $(NAME)

$(NAME): $(OBJ)
	$(CC) $(SRC) $(M_FLAGS) -o $(NAME)

$(LIB):
	make -C ./min

.c.o:
	$(CC) $(C_FLAGS) -c $< -o $@

clean:
	$(RM) *.o

fclean: clean
	make clean -C ./min
	$(RM) $(NAME)

norm:
	norminette ./*.c

re: fclean all

.PHONY: all clean fclean re