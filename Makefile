NAME = game
CC = gcc
SRCS = $(wildcard ./srcs/*.c)
HEADER = $(wildcard ./includes/*.h)

all		:	${NAME}

${NAME}	:	${HEADER} ${SRCS}
	$(CC) -o $(NAME) ${SRCS} -L ~/.brew/opt/readline/lib -l readline -I includes -I ~/.brew/opt/readline/include
