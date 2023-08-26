# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfredes- <gfredes-@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 23:21:44 by gfredes-          #+#    #+#              #
#    Updated: 2023/08/26 14:01:32 by gfredes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

#CFLAGS = -Wall -Wextra -Werror

CLEAN = rm -f

SRC = 	push_swap_operations.c \
				operations_utils.c \
				main.c \
				sorts.c \
				init.c \
				check_args.c \
				utils.c \
				reverse_rotate_operations.c \
				rotate_operations.c \
				lis_utils.c \
				check_sort.c \
				lis.c \
				moves.c \
				calculate_costs.c \
				update_positions.c \
				move_pointers.c \
				moves_utils.c \
				init_utils.c \
				calculate_costs_utils.c \
				calculate_costs_utils2.c

CC = gcc -g

OBJT = $(SRC:.c=.o)

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

$(NAME): $(LIBFT) $(OBJT)
	$(CC) $(SRC) $(LIBFT) -o $(NAME)


clean:
	$(CLEAN) $(OBJT)
	make -C ./libft clean
fclean: clean
	$(CLEAN) $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
