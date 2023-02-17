NAME = $(shell basename $(CURDIR))


SRCS	= ${wildcard SRCS/*.c} ${wildcard SRCS/*/*.c} ${wildcard SRCS/*/*/*.c} ${wildcard get_next_line/*.c} ${wildcard MAP/*.c}

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
# CC			= 	cc #-Wall -Wextra -Werror  -g # -fsanitize=address
# RM			= 	/bin/rm -f
# NAME		= 	cub3D
# INCLUDES	= 	-Iinclude/
# SRCS		=   $(shell find SRCS/ -name '*.c')
# OBJS		= 	$(SRCS:.c=.o)


# MLX_LIB_DIR = mlx_linux/
# #directories with .h
# LIBFT_INCLUDE = -ILIBFT/include
# MLX_INCLUDE = -Imlx_linux

# COLOUR_GREEN=\033[7;1;32m
# COLOUR_END=\033[0m
# COLOUR_YELLOW=\033[7;1;33m

# MLX_FLAGS = -L$(MLX_LIB_DIR) -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

# # ^ primeira dependencia
# # @ nome da regra
# all: $(NAME)

# $(NAME): $(OBJS) 
# 	@$(MAKE) -s -C mlx_linux
# 	@$(CC) $(^) $(MLX_FLAGS) -o $(@)

# %.o: %.c $(MLX_LIB)
# 	@$(CC) $(INCLUDES) $(MLX_INCLUDE) -c $(^) -o $(@)

# bonus: all

# clean:
# 	@$(RM) $(OBJS)
# 	@echo "\033[0;31mREMOVED OBJECT FILES\033[0m"

# fclean: clean
# 	@$(RM) $(NAME)
# 	@echo "\033[0;31mREMOVED cub3D EXECUTABLE\033[0m"

# re: fclean all

# norm :
# 	@norminette -R CheckForbiddenSourceHeader $(SRCS) headers/

# m: fclean

# v:
# 	@make re && make clean && clear && valgrind ./cub3D map/map1.cub

# vv:
# 	@make re && make clean && clear && valgrind --leak-check=full --log-file="logfile.out" -v ./cub3D map/map14.cub
# r:
# 	@make re && make clean && clear && ./cub3D map/map3.cub map/map1.cub map/map2.cub teste dfsdsdfsdfs/sasd

# rr:
# 	@make re && make clean && clear && ./cub3D map/*


# .PHONY: all re clean fclean m
