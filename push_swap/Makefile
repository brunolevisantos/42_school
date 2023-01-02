SOURCES = push_swap.c

SOURCESUTILS = add_node.c \
		atoi_two.c \
		list_clear.c \
		run_algorithm.c \
		string_clear.c

SOURCESOPS = push.c \
		rev_rotate.c \
		rotate.c \
		swap.c

SOURCESLIBFT = ft_split.c \
		ft_calloc.c \
		ft_memmove.c \
		ft_bzero.c \
		ft_memset.c

SOURCESUTILSF = $(addprefix utils/, $(SOURCESUTILS))

SOURCESLIBFTF = $(addprefix utils/libft_utils/, $(SOURCESLIBFT))

SOURCESOPSF = $(addprefix utils/operations/, $(SOURCESOPS))

OBJECTS = $(SOURCES:.c=.o)
OBJECTSUTILS = $(SOURCESUTILSF:.c=.o)
OBJECTSOPS = $(SOURCESOPSF:.c=.o)
OBJECTSLIBFT = $(SOURCESLIBFTF:.c=.o)

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTSUTILS) $(OBJECTSOPS) $(OBJECTSLIBFT)
	@$(CC) $(CFLAGS) $(OBJECTS) $(OBJECTSUTILS) $(OBJECTSOPS) $(OBJECTSLIBFT) -o $(NAME)

clean:
	@rm -f *.o utils/*.o utils/operations/*.o utils/libft_utils/*.o

fclean: clean
	@rm -f push_swap

re: fclean all