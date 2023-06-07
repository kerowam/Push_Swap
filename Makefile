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

NAME = push_swap.a
CFLAGS = -Wall -Wextra -Werror
CLEAN = rm -f
SRC = push_swap_operations.c /
			push_swap_utils.c /
			push_swap.c /


CC = gcc -c
OBJT = $(SRC:.c=.o)


all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(SRC)
	ar rcs $(NAME) $(OBJT)

clean:
	$(CLEAN) $(OBJT) 

fclean: clean
	$(CLEAN) $(NAME)

re: fclean all

.PHONY: all clean fclean re 