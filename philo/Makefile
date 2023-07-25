NAME = philo

SRCS	= SRCS/check_args.c \
		SRCS/fill_philos.c \
		SRCS/free_philos.c \
		SRCS/get_mutex_next.c \
		SRCS/get_mutex.c \
		SRCS/get_time.c \
		SRCS/my_sleep.c \
		SRCS/philo.c \
		SRCS/routine.c \
		SRCS/utils/ft_calloc.c \
		SRCS/utils/new_atoi.c

OBJ		= ${SRCS:.c=.o}

CC		= cc

CFLAGS	= -Wall -Werror -Wextra -pthread -g #-fsanitize=thread

all: $(NAME)

%.o: %.c
	$(CC) -pthread -Wall -Wextra -Werror -g3 -O3 -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf ${OBJ}

fclean: clean
	rm -rf ${NAME}

norm:
	norminette -R CheckForbiddenSourceHeader SRCS/*
	norminette -R CheckDefine INCS/*

re: fclean all

	