SOURCES	= get_next_line.c \
		get_next_line_utils.c \
		main.c

BONUS = get_next_line_bonus.c \
		get_next_line_utils_bonus.c

OBJECTS	= ${SOURCES:.c=.o}

BONUS_OBJECTS = ${BONUS:.c=.o}

CC		= cc

CFLAGS	= -Wall -Werror -Wextra -fsanitize=address -g

NAME	= get_next_line.a

${NAME}:
	${CC} -c ${CFLAGS} ${SOURCES}
	ar rcs ${NAME} ${OBJECTS}

all: ${NAME}

clean: 
	rm -rf ${OBJECTS} ${BONUS_OBJECTS}

fclean: clean
	rm -rf ${NAME}

re: fclean bonus

bonus: 
	${CC} -c ${CFLAGS} ${SOURCES} get_next_line.h
	${CC} -c ${CFLAGS} ${BONUS} get_next_line.h
	ar rsc ${NAME} ${OBJECTS} ${BONUS_OBJECTS}

.PHONY: all clean fclean re
