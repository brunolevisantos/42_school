NAME = $(shell basename $(CURDIR))

SRCS	= bonus/print_moves.c \
		bonus/get_time.c \
		bonus/bonus.c \
		handle/handle_msg.c \
		handle/handle_no_event.c \
		handle/handle_keypress.c \
		utils/ft_strjoin.c \
		utils/get_next_line/get_next_line_utils.c \
		utils/get_next_line/get_next_line.c \
		utils/ft_printf/ft_strlen_print.c \
		utils/ft_printf/ft_putpointer_fd.c \
		utils/ft_printf/ft_putnbr_fd.c \
		utils/ft_printf/ft_putstr_fd.c \
		utils/ft_printf/ft_printf.c \
		utils/ft_printf/ft_puthex_fd.c \
		utils/ft_printf/ft_putchar_fd.c \
		utils/ft_memset.c \
		utils/ft_strlen.c \
		utils/ft_bzero.c \
		utils/ft_calloc.c \
		utils/ft_itoa.c \
		ft_close.c \
		initialize.c \
		so_long.c \
		map_utils/check_map_name.c \
		map_utils/load_map_zico.c \
		map_utils/map_free.c \
		map_utils/elem_count.c \
		map_utils/check_path.c \
		map_utils/line_count.c \
		map_utils/map_checker.c \
		map_utils/map_copy.c \
		render/fill_obj.c \
		render/draw_floor.c \
		render/decide_img.c \
		render/render.c \
		render/my_pixel_put.c

OBJ		= ${SRCS:.c=.o}

CC		= cc

CFLAGS	= -Wall -Werror -Wextra -g3 -O3 -fsanitize=address

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -g3 -I/usr/include -Imlx_linux -O3 -c $< -o $@

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
	./so_long
	