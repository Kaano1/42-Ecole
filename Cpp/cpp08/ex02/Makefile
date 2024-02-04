NAME			=	mutantstack

SRCS			=	main.cpp

OBJS			=	$(SRCS:%.cpp=%.o)

CPP				= 	c++
RM				= 	rm -rf
CXXFLAGS		= 	-Wall -Wextra -Werror -std=c++98

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CPP) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

.PHONY:			all clean fclean re bonus