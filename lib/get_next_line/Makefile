NAME		=	libgnl.a

SRCS		=	get_next_line.c get_next_line_utils.c

OBJS		=	${SRCS:.c=.o}

CC			=	gcc

CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm -f

%.o:			%.c
				${CC} ${CFLAGS} -c $< -o $@

all:			${NAME}

${NAME}:		${OBJS}
				ar rcs ${NAME} ${OBJS}

clean:
				rm -f ${OBJS}

fclean:			clean
				${RM} ${NAME}

re:				fclean all

test:		${OBJS}
			${CC} ${OBJS} -o test

.PHONY:			all clean fclean re
