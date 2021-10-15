SERVER = server
CLIENT = client
SERVER_BON = server_bon
CLIENT_BON = client_bon

CFLAGS = -Wall -Wextra -Werror

CC	 = gcc

HEADER = minitalk.h

RM = rm -f

SRV_SRC =	server.c

CLT_SRC =	client.c

SRV_BON_SRC =	server.c

CLT_BON_SRC =	client_bonus.c

SRV_OBJS	= ${SRV_SRC:.c=.o}
CLT_OBJS	= ${CLT_SRC:.c=.o}

SRV_BON_OBJS	= ${SRV_BON_SRC:.c=.o}
CLT_BON_OBJS	= ${CLT_BON_SRC:.c=.o}

all:	$(SERVER) $(CLIENT)

.c.o:
	${CC} ${CFLAGS} -c -g $< -o ${<:.c=.o}

$(SERVER):	$(SRV_OBJS)
				$(CC) $(SRV_OBJS) $(CFLAGS) -g -o $(SERVER)

$(CLIENT):	$(CLT_OBJS)
				$(CC) $(CLT_OBJS) $(CFLAGS) -g -o $(CLIENT)

$(SERVER_BON):	$(SRV_BON_OBJS)
				$(CC) $(SRV_BON_OBJS) $(CFLAGS) -g -o $(SERVER_BON)

$(CLIENT_BON):	$(CLT_BON_OBJS)
				$(CC) $(CLT_BON_OBJS) $(CFLAGS) -g -o $(CLIENT_BON)

bonus:	${SERVER_BON} ${CLIENT_BON}

clean:
	${RM} ${SRV_OBJS} ${CLT_OBJS} ${SRV_BON_OBJS} ${CLT_BON_OBJS}

fclean:	 clean
		${RM} ${SERVER} ${CLIENT} ${SERVER_BON} ${CLIENT_BON}

re: 	fclean all

.PHONY:  all clean fclean re