# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrakhman <mrakhman@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/30 19:03:50 by mrakhman          #+#    #+#              #
#    Updated: 2018/09/30 17:37:20 by mrakhman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= fractol

# compiler
C_FLAGS		= -Wall -Wextra -Werror
CC			= gcc

# mlx library
MLX_PATH	= ./minilibx_macos/
MLX_LIB 	= libmlx.a
MLX_INC 	= -lmlx -framework OpenGL -framework AppKit

# ft library
LIBFT		= ./libft/libft.a

INCLUDE 	=  -I. $(LIBFT) -L $(MLX_PATH) $(MLX_INC)

SRC = \
main \
mandelbrot \
julia \
burningship \
init \
color_pixel \
keyboard \
mouse \
error \

OBJ		= $(addsuffix .o,$(SRC))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(C_FLAGS) $(INCLUDE) $(OBJ) -o $(NAME)
	@echo "$(NAME) - compiled!"

$(LIBFT):
	@make -C ./libft/

%.o: %.c
	$(CC) -c $(C_FLAGS) $< -o $@

clean:
	@rm -rf $(OBJ)
	@make fclean -C ./libft
	@echo "Cleaning $(NAME) - comlete."

fclean: clean
	@rm -f $(NAME) $(OBJ)
	@echo "$(NAME) - deleted."

re: fclean all
