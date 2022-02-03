NAME	= pipex.a
PROG	= pipex

SRCS	= srcs/pipex.c srcs/utils.c
OBJS	= ${SRCS:.c=.o}
MAIN	= srcs/pipex.c

HEADER	= includes/pipex.h

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

.c.o	: %.o : %.c
	@gcc ${CFLAGS} -I ${HEADER} -c $< -o $(<:.c=.o)

all		: ${NAME}

${NAME}	:	${OBJS} ${HEADER}
	@ar -rcs ${NAME} ${OBJS}

clean	:
	@rm -rf ${OBJS}

fclean	: clean
	@rm -rf ${NAME}

re		: fclean all