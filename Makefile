# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mkabirov <mkabirov@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/14 14:08:57 by mkabirov          #+#    #+#              #
#    Updated: 2020/01/05 23:02:10 by mkabirov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fractol

FRAEMWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall
SOURCES=sources/*.c
LIBRARIES=libft/libft.a minilibx_macos/libmlx.a

all:
	@make -C libft/ all
	@make -C minilibx_macos/
	gcc $(SOURCES) -o $(NAME) $(LIBRARIES) $(FRAEMWORKS) $(FLAGS)

	@echo "\nProgram compiled!\n"
	@echo "Choose Fractal to display:\n1 - Mandelbrot, 2 - Julia Fractal \
	3 - Burning Ship, 4 - MandelCat"
	@echo "Please run executable:  \n./fractol 1 or 2, 3, 4"

runman:
	./fractal

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all
