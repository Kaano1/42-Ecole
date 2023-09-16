SRCS = main.cpp Bureaucrat.cpp
OBJS = $(SRCS:%.c=%.o)
C++ = c++
CPPFLAGS = #-Wall -Wextra -Werror -std=c++98
NAME = bureaucrat
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(C++) $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) *.o

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all