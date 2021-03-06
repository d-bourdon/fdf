#* ************************************************************************** *#
#*                                                                            *#
#*                                                        :::      ::::::::   *#
#*   Makefile                                           :+:      :+:    :+:   *#
#*                                                    +:+ +:+         +:+     *#
#*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        *#
#*                                                +#+#+#+#+#+   +#+           *#
#*   Created: 2016/06/15 14:15:13 by dbourdon          #+#    #+#             *#
#*   Updated: 2016/10/20 15:49:34 by dbourdon         ###   ########.fr       *#
#*                                                                            *#
#* ************************************************************************** *#

NAME = fdf

SRC = 	*.c

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: clean fclean re libft norme mlx

all: $(NAME)

$(NAME) : libft mlx $(OBG)
	-@clang $(FLAGS) $(SRC) -g -o $(NAME) -L./libft/ -lft -L./mlx/ -lmlx -framework OpenGL -framework AppKit
	@echo "Compilation"

libft:
	-@make -C libft/

clean: 
	-@make -C libft/ clean
	-@rm -f $(OBJ) *.gch
	@echo "Supression"

fclean: clean
	-@rm -f $(NAME)
	-@make -C libft/ fclean
	@echo "totale..."

re: fclean all
	-@make re -C libft/

norme:
	@norminette *.[ch] ./libft/*.[ch]

mlx:
	-@make -C mlx/
