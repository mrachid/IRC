# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/22 09:13:01 by mrachid           #+#    #+#              #
#    Updated: 2014/05/08 15:01:56 by mrachid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

FLAG = -Wall -Werror -Wextra -O3

INCL = ./includes

OBJ = $(SRC:.c=.o)

CC = gcc

SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putendl.c ft_putchar_fd.c \
	  ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strlen.c ft_strclr.c \
	  ft_strcpy.c ft_strncpy.c ft_strcmp.c ft_strncmp.c ft_strequ.c \
	  ft_strnequ.c ft_atoi.c ft_isalnum.c ft_isalpha.c ft_isdigit.c \
	  ft_isprint.c ft_isascii.c ft_toupper.c ft_tolower.c ft_memset.c \
	  ft_bzero.c ft_memcpy.c ft_memmove.c ft_strcat.c ft_strncat.c \
	  ft_strdup.c ft_strstr.c ft_strnstr.c ft_memccpy.c ft_memchr.c \
	  ft_memcmp.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_memalloc.c \
	  ft_memdel.c ft_strdel.c ft_strnew.c ft_strsub.c ft_strjoin.c \
	  ft_strtrim.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	  ft_strreverse.c ft_itoa.c ft_strsplit.c ft_lstnew.c ft_lstadd.c \
	  ft_lstrev.c ft_lstaddend.c ft_lst_db_new.c ft_lst_db_add.c \
	  ft_lst_db_addend.c get_next_line.c

.PHONY: all clean fclean re

all: $(NAME)

$(NAME):
	@$(CC) $(FLAG) -c $(SRC) -I $(INCL)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
