SOURCES	= get_next_line2.c \
		ft_strlen.c \
		ft_strchr.c \
		ft_strjoin.c \
		main.c \
		move_buf.c

OBJECTS	= ${SOURCES:.c=.o}

CC		= cc

CFLAGS	= -Wall -Werror -Wextra

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
