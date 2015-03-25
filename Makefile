# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/18 23:13:43 by mrachid           #+#    #+#              #
#    Updated: 2015/02/20 14:24:48 by mrachid          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMESERVER = serveur

NAMECLIENT = client

CPATH =		./

HPATH =		-I libft/includes/

INCLUDES = 	-L libft/libft.a

SRCSERVER	= 	ft_server.c ft_server_function.c

SRCCLIENT 	= 	client.c client_function.c

SRCOTHER	= 	ft_list_member.c ft_error.c ft_ncurses.c check.c \
				ft_channel.c ft_command.c ft_server_diver.c

OBJSSERVER 	=	$(SRCSERVER:.c=.o)

OBJSCLIENT	= 	$(SRCCLIENT:.c=.o)

OBJSOTHER	=	$(SRCOTHER:.c=.o)

CC =		gcc

CFLAGS =	-Wall -Wextra -Werror

RM =		rm -rf

all:		serveur client

make:
	@make -C libft/

serveur:	$(OBJSSERVER) $(OBJSOTHER)
				@$(CC) $(CFLAGS) $(OBJSSERVER) $(OBJSOTHER) -o $(NAMESERVER) -L libft -lft -lncurses
				@echo "\033[32m[..: The Server has been compiled :..]\033[0m"

client:		$(OBJSCLIENT) $(OBJSOTHER)
				@$(CC) $(CFLAGS) $(OBJSCLIENT) $(OBJSOTHER) -o $(NAMECLIENT) -L libft -lft -lncurses
				@echo "\033[32m[..: The Client has been compiled :..]\033[0m"

%.o : %.c
	@make -C libft/
	@$(CC) $(CFLAGS) -g -I libft/includes/ $(FLAG) -c $^ $(HPATH)

clean:
		@make -C libft/ clean
		@/bin/rm -rf $(OBJSCLIENT)
		@/bin/rm -rf $(OBJSSERVER)
		@/bin/rm -rf $(OBJSOTHER)

fclean:	clean
		@make -C libft/ fclean
		@/bin/rm -f $(NAMECLIENT)
		@/bin/rm -f $(NAMESERVER)

re:		fclean all
