#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acouliba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/12 11:46:25 by acouliba          #+#    #+#              #
#    Updated: 2015/05/29 21:18:46 by qrosa            ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC:=./srcs/main.c\
./srcs/ft_fdf.c\
./srcs/ft_get_maps.c\
./srcs/ft_get_one_map.c\
./srcs/ft_recup_param_map.c\
./srcs/ft_create_elem.c\
./srcs/ft_push_back.c\
./srcs/ft_draw_grille.c\
./srcs/ft_draw_segment.c\
./srcs/ft_draw_segment_2.c\
./srcs/ft_draw_segment_dx_sup.c\
./srcs/ft_draw_segment_dx_inf.c\
./srcs/ft_key_hook.c\
./srcs/ft_key_sup.c\
./srcs/ft_print_error.c

OBJ=$(SRC:.c=.o)

# Lib includes
INC=-I ./includes/
LIBFT=libft/libft.a
LIB=-L ./libft/ -lft
MLX=minilibx_macos/libmlx.a
LIBMLX=-L ./minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

# Options can be changed
CFLAGS+:=-Wall -Wextra -Werror
CC:=gcc
NAME:=fdf

# Sweet colors just for swag :)

RED=\033[0;31m
BLUE=\033[1;34m
CYAN=\033[0;36m
ORANGE=\033[0;33m
GREEN=\033[1;32m
NC=\033[0m

all:$(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@make -C libft

$(MLX):
	@make -C minilibx_macos

$(NAME): $(OBJ)
	@echo "${BLUE}--Linking $(NAME)${NC}"
	@$(CC) $(OBJ) $(CFALGS) -o $(NAME) $(INC) $(LIB) $(LIBMLX)

%.o: %.c
	@echo "${CYAN}Compiling $^ into $@ ${NC}";
	@$(CC) -c $^ -o $@ $(CFLAGS) $(INC)

clean:
	@make clean -C libft
	@make clean -C minilibx_macos
	@echo "${ORANGE}--Delete fdf/libft/mlx OBJS OK ${NC}";
	@rm -f $(OBJ)

fclean: clean
	@echo "${RED}--Remove $(LIBFT)${NC}"
	@rm -f $(LIBFT)
	@echo "${RED}--Remove $(MLX)${NC}"
	@rm -f $(MLX)
	@echo "${RED}--Remove $(NAME)${NC}"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
