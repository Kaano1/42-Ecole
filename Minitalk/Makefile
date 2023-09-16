SERVER			=	server
SERVER_SRC		=	server.c
SERVER_OBJ		=	$(SERVER_SRC:.c=.o)

CLIENT			=	client
CLIENT_SRC		=	client.c
CLIENT_OBJ		=	$(CLIENT_SRC:.c=.o)

CC				=	gcc
RM 				=	rm -rf
FLAGS			= 	-Wall -Werror -Wextra

all : $(SERVER) $(CLIENT)

$(SERVER) : $(SERVER_OBJ)
	$(CC) $(FLAGS) $(SERVER_SRC) -o $(SERVER)


$(CLIENT) : $(CLIENT_OBJ)
	$(CC) $(FLAGS) $(CLIENT_SRC) -o $(CLIENT)
	
%.o : %.c
	@$(CC) $(FLAGS) $< -c -I includes

fclean :
	$(RM) $(SERVER) $(CLIENT)


re : fclean all

.PHONY: all fclean re server.o client.o
