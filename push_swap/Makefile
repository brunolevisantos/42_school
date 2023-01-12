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

BONUSSRC = checker.c

BONUSUTILS = checker_push.c \
		checker_rev_rotate.c \
		checker_rotate.c \
		checker_swap.c \
		my_strcmp.c \
		run_checker.c

BONUSGNLSRC = get_next_line_utils.c \
		get_next_line.c

SOURCESUTILSF = $(addprefix utils/, $(SOURCESUTILS))

SOURCESLIBFTF = $(addprefix utils/libft_utils/, $(SOURCESLIBFT))

SOURCESOPSF = $(addprefix utils/operations/, $(SOURCESOPS))

SOURCESSORTF = $(addprefix utils/sort_utils/, $(SOURCESSORT))

SOURCESBONUSUTILSF = $(addprefix checker_utils/, $(BONUSUTILS))

SOURCESBONUSGNLSRCF = $(addprefix get_next_line/, $(BONUSGNLSRC))

OBJECTS = $(SOURCES:.c=.o)
OBJECTSUTILS = $(SOURCESUTILSF:.c=.o)
OBJECTSOPS = $(SOURCESOPSF:.c=.o)
OBJECTSLIBFT = $(SOURCESLIBFTF:.c=.o)
OBJECTSSORT = $(SOURCESSORTF:.c=.o)
OBJECTSBONUS = $(BONUSSRC:.c=.o)
OBJECTSBONUSUTILS = $(SOURCESBONUSUTILSF:.c=.o)
OBJECTSBONUSGNLSRC = $(SOURCESBONUSGNLSRCF:.c=.o)

NAME = push_swap

BONUSNAME = checker

CC = cc

CFLAGS = -Wall -Werror -Wextra -fsanitize=address -g -O3

all: $(NAME)

$(NAME): $(OBJECTS) $(OBJECTSUTILS) $(OBJECTSOPS) $(OBJECTSLIBFT) $(OBJECTSSORT)
	@$(CC) $(CFLAGS) $(OBJECTS) $(OBJECTSUTILS) $(OBJECTSOPS) $(OBJECTSLIBFT) $(OBJECTSSORT) -o $(NAME)

clean:
	@rm -f *.o utils/*.o utils/operations/*.o utils/libft_utils/*.o utils/sort_utils/*.o checker_utils/*.o get_next_line/*.o

fclean: clean
	@rm -f push_swap checker

re: fclean all bonus

bonus: $(BONUSNAME)

$(BONUSNAME): $(OBJECTSUTILS) $(OBJECTSOPS) $(OBJECTSLIBFT) $(OBJECTSSORT) $(OBJECTSBONUS) $(OBJECTSBONUSUTILS) $(OBJECTSBONUSGNLSRC)
	@$(CC) $(CFLAGS) $(OBJECTSUTILS) $(OBJECTSOPS) $(OBJECTSLIBFT) $(OBJECTSSORT) $(OBJECTSBONUS) $(OBJECTSBONUSUTILS) $(OBJECTSBONUSGNLSRC) -o $(BONUSNAME)