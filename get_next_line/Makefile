SOURCES	= get_next_line.c \
		get_next_line_utils.c \
		main.c

OBJECTS	= ${SOURCES:.c=.o}

CC		= cc

CFLAGS	= -Wall -Werror -Wextra -fsanitize=address -g

NAME	= get_next_line.a

${NAME}:
	${CC} ${CFLAGS} ${SOURCES}

all: ${NAME}

clean: 
	rm -rf ${OBJECTS}

fclean: clean
	rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
