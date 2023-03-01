NAME = $(shell basename $(CURDIR))

SRCS	= SRCS/bonus/print_moves.c \
		SRCS/bonus/get_time.c \
		SRCS/bonus/bonus.c \
		SRCS/handle/handle_msg.c \
		SRCS/handle/handle_no_event.c \
		SRCS/handle/handle_keypress.c \
		SRCS/utils/ft_strjoin.c \
		SRCS/utils/get_next_line/get_next_line_utils.c \
		SRCS/utils/get_next_line/get_next_line.c \
		SRCS/utils/ft_printf/ft_strlen_print.c \
		SRCS/utils/ft_printf/ft_putpointer_fd.c \
		SRCS/utils/ft_printf/ft_putnbr_fd.c \
		SRCS/utils/ft_printf/ft_putstr_fd.c \
		SRCS/utils/ft_printf/ft_printf.c \
		SRCS/utils/ft_printf/ft_puthex_fd.c \
		SRCS/utils/ft_printf/ft_putchar_fd.c \
		SRCS/utils/ft_memset.c \
		SRCS/utils/ft_strlen.c \
		SRCS/utils/ft_bzero.c \
		SRCS/utils/ft_calloc.c \
		SRCS/utils/ft_itoa.c \
		SRCS/ft_close.c \
		SRCS/initialize.c \
		SRCS/so_long.c \
		SRCS/map_utils/check_map_name.c \
		SRCS/map_utils/load_map_zico.c \
		SRCS/map_utils/map_free.c \
		SRCS/map_utils/elem_count.c \
		SRCS/map_utils/check_path.c \
		SRCS/map_utils/line_count.c \
		SRCS/map_utils/map_checker.c \
		SRCS/map_utils/map_copy.c \
		SRCS/render/fill_obj.c \
		SRCS/render/draw_floor.c \
		SRCS/render/decide_img.c \
		SRCS/render/render.c \
		SRCS/render/my_pixel_put.c

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
	