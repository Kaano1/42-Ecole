NAME = template
SRCS = main.cpp
OBJS = $(SRCS:.cpp=.o)

CC = c++
CXXFLAGS = -Wall -Wextra -Werror --std=c++98
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
