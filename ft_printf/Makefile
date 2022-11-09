SOURCES	= ft_printf.c \
		ft_putchar_fd.c \
		ft_puthex_fd.c \
		ft_putnbr_fd.c \
		ft_putpointer_fd.c \
		ft_putstr_fd.c \
		ft_strlen.c

OBJECTS			= ${SOURCES:.c=.o}

FULLGCC			= cc -Wall -Werror -Wextra

NAME			= libftprintf.a

${NAME}:
	${FULLGCC} -c ${SOURCES}
	ar rcs ${NAME} ${OBJECTS}

all: ${NAME}

clean: 
	rm -rf ${OBJECTS}

fclean: clean
	rm -rf ${NAME}

re: fclean

.PHONY: all clean fclean re
