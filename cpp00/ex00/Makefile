C++ = g++
SRCS = megaphone.cpp
OBJ = $(SRCS:.cpp=.o)
NAME = megaphone
CPPFLAGS = -Wall -Wextra -Werror
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(C++) $(CPPFLAGS) $(SRCS) -o $(NAME) -std=c++98

fclean: clean
	$(RM) $(NAME)

clean:
	$(RM) *.o

.PHONY: all clean