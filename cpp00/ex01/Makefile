C++ = g++
SRCS = phone.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = mobilePhone
FLAGS = #-Wall -Wextra -Werror -std=c++98
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	$(C++) $(FLAGS) $(SRCS) -o $(NAME)

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) *.o

.PHONY: all fclean clean