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
								main.c \

LIBFT_SRC = libft/ft_isalpha.c \
						libft/ft_isdigit.c \
						libft/ft_isalnum.c \
						libft/ft_isascii.c \
						libft/ft_isprint.c \
						libft/ft_strlen.c \
						libft/ft_memset.c \
						libft/ft_bzero.c \
						libft/ft_memcpy.c \
						libft/ft_memmove.c \
						libft/ft_strlcpy.c \
						libft/ft_strlcat.c \
						libft/ft_toupper.c \
						libft/ft_tolower.c \
						libft/ft_strchr.c \
						libft/ft_strrchr.c \
						libft/ft_strncmp.c \
						libft/ft_memchr.c \
						libft/ft_memcmp.c \
						libft/ft_strnstr.c \
						libft/ft_atoi.c \
						libft/ft_calloc.c \
						libft/ft_strdup.c \
						libft/ft_substr.c \
						libft/ft_strjoin.c \
						libft/ft_strtrim.c \
						libft/ft_split.c \
						libft/ft_itoa.c \
						libft/ft_strmapi.c \
						libft/ft_striteri.c \
						libft/ft_putchar_fd.c \
						libft/ft_putstr_fd.c \
						libft/ft_putendl_fd.c \
						libft/ft_putnbr_fd.c \
						libft/ft_printf.c \
						libft/get_next_line.c \
						libft/ft_lstnew_bonus.c \
		   			libft/ft_lstadd_front_bonus.c \
		   			libft/ft_lstsize_bonus.c \
		   			libft/ft_lstlast_bonus.c \
		   			libft/ft_lstadd_back_bonus.c \
		   			libft/ft_lstdelone_bonus.c \
		   			libft/ft_lstclear_bonus.c \
		   			libft/ft_lstiter_bonus.c \
		   			libft/ft_lstmap_bonus.c

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