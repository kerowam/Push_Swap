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


CFLAGS = -Wall -Wextra -Werror
CLEAN = rm -f
PUSH_SWAP_SRC = push_swap_operations.c \
								push_swap_utils.c \
								push_swap.c \

LIBFT_SRC = ft_isalpha.c \
						ft_isdigit.c \
						ft_isalnum.c \
						ft_isascii.c \
						ft_isprint.c \
						ft_strlen.c \
						ft_memset.c \
						ft_bzero.c \
						ft_memcpy.c \
						ft_memmove.c \
						ft_strlcpy.c \
						ft_strlcat.c \
						ft_toupper.c \
						ft_tolower.c \
						ft_strchr.c \
						ft_strrchr.c \
						ft_strncmp.c \
						ft_memchr.c \
						ft_memcmp.c \
						ft_strnstr.c \
						ft_atoi.c \
						ft_calloc.c \
						ft_strdup.c \
						ft_substr.c \
						ft_strjoin.c \
						ft_strtrim.c \
						ft_split.c \
						ft_itoa.c \
						ft_strmapi.c \
						ft_striteri.c \
						ft_putchar_fd.c \
						ft_putstr_fd.c \
						ft_putendl_fd.c \
						ft_putnbr_fd.c \
						ft_printf.c \
						get_next_line.c \
						ft_lstnew_bonus.c \
		   			ft_lstadd_front_bonus.c \
		   			ft_lstsize_bonus.c \
		   			ft_lstlast_bonus.c \
		   			ft_lstadd_back_bonus.c \
		   			ft_lstdelone_bonus.c \
		   			ft_lstclear_bonus.c \
		   			ft_lstiter_bonus.c \
		   			ft_lstmap_bonus.c

SRC = $(PUSH_SWAP_SRC) $(LIBFT_SRC)


CC = gcc -c
OBJT = $(SRC:.c=.o)


all: push_swap

push_swap: $(OBJT)
	$(CC) $(CFLAGS) -o $@ $^

libft: $(LIBFT_SRC)
	$(CC) $(CFLAGS) -c $(LIBFT_SRC)
	ar rcs libft.a $(OBJT)

clean:
	$(CLEAN) $(OBJT) 

fclean: clean
	$(CLEAN) push_swap libft.a

re: fclean all

.PHONY: all push_swap libft clean fclean re