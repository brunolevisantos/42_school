NAME = $(shell basename $(CURDIR))

SRCS	= ${wildcard SRCS/*.c} ${wildcard SRCS/*/*.c} ${wildcard SRCS/*/*/*.c}

OBJ		= ${SRCS:.c=.o}

CC		= cc

CFLAGS	= -Wall -Werror -Wextra -g3 -O3 -fsanitize=address

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g3 -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

project:
	@mkdir include
	@touch include/$(NAME).h
	@mkdir SRCS
	@touch SRCS/$(NAME).c
	@touch report.txt

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

norm:
	norminette -R CheckForbiddenSourceHeader SRCS/*
	norminette -R CheckDefine INCS/*

re: fclean all

r: all
	./pipex
	