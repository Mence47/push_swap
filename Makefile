# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtroll <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/23 19:34:02 by rtroll            #+#    #+#              #
#    Updated: 2019/02/09 17:27:44 by rtroll           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = checker

NAME2 = push_swap

SRC = checker_main.c\
	  stack_functions.c\
	  error_functions.c\
	  moves.c\
	  moves_2.c\
	  operations.c\
	  get_commands.c

SRC2 =	push_swap_main.c\
		quicksort.c\
		moves_ps.c\
		moves_2_ps.c\
		sort.c\
		sort_b.c\
		sort_three_a.c\
		sort_seven.c\
		sort_seven_b.c\
		sort_help_functions.c\
		optimaze.c

OBJ = $(SRC:.c=.o)

OBJ2 = $(SRC2:.c=.o)

SRC_PATH = src/

SRC_POS = $(addprefix $(SRC_PATH), $(SRC))

SRC_POS2 = $(addprefix $(SRC_PATH), $(SRC2))

INC = -I include

LIBFT = src/libft/libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra 

all: $(NAME) $(NAME2)

$(NAME): $(LIBFT) $(OBJ)
	    @$(CC) $(FLAGS) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
	    @$(CC) $(FLAGS) -c $(SRC_POS) $(INC)

$(NAME2): $(LIBFT) $(OBJ2)
	    @$(CC) $(FLAGS) $(OBJ2) moves_2.o error_functions.o stack_functions.o -o $(NAME2) $(LIBFT)

$(OBJ2): $(LIBFT)
	    @$(CC) $(FLAGS) -c $(SRC_POS2) $(INC)

$(LIBFT):
	    @make -C ./src/libft/

clean:
		@rm -f $(OBJ)
		@rm -f $(OBJ2)
		@make clean -C ./src/libft/

fclean: clean
		@rm -f $(NAME)
		@rm -f $(NAME2)
		@make fclean -C ./src/libft

re: fclean all
