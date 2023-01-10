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
		ft_memset.c \
		list_size.c

SOURCESSORT = bst_to_top.c \
		sort_three.c \
		sort_general.c \
		below_avg_to_b.c \
		max_node.c \
		min_node.c \
		least_cost.c \
		best_neighbour.c

SOURCESUTILSF = $(addprefix utils/, $(SOURCESUTILS))

SOURCESLIBFTF = $(addprefix utils/libft_utils/, $(SOURCESLIBFT))

SOURCESOPSF = $(addprefix utils/operations/, $(SOURCESOPS))

SOURCESSORTF = $(addprefix utils/sort_utils/, $(SOURCESSORT))

OBJECTS = $(SOURCES:.c=.o)
OBJECTSUTILS = $(SOURCESUTILSF:.c=.o)
OBJECTSOPS = $(SOURCESOPSF:.c=.o)
OBJECTSLIBFT = $(SOURCESLIBFTF:.c=.o)
OBJECTSSORT = $(SOURCESSORTF:.c=.o)

NAME = push_swap

CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g -O3

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTSUTILS) $(OBJECTSOPS) $(OBJECTSLIBFT) $(OBJECTSSORT)
	@$(CC) $(CFLAGS) $(OBJECTS) $(OBJECTSUTILS) $(OBJECTSOPS) $(OBJECTSLIBFT) $(OBJECTSSORT) -o $(NAME)

clean:
	@rm -f *.o utils/*.o utils/operations/*.o utils/libft_utils/*.o utils/sort_utils/*.o

fclean: clean
	@rm -f push_swap

re: fclean all