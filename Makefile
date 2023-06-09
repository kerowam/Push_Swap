# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gfredes- <gfredes-@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 23:21:44 by gfredes-          #+#    #+#              #
#    Updated: 2023/06/06 23:21:44 by gfredes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

CLEAN = rm -f

SRC = 	push_swap_operations.c \
				operations_utils.c \
				main.c \
				sorts.c \
				init.c \
				check.c \
				utils.c \
				reverse_rotate_operations.c \
				rotate_operations.c

CC = gcc

OBJT = $(SRC:.c=.o)

LIBFT = libft/libft.a

all: $(LIBFT) $(NAME)

$(LIBFT):
	make -C ./libft

$(NAME): $(LIBFT) $(OBJT)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)


clean:
	$(CLEAN) $(OBJT)
	make -C ./libft clean
fclean: clean
	$(CLEAN) $(NAME)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re