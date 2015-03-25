/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 10:14:10 by mrachid           #+#    #+#             */
/*   Updated: 2015/03/09 10:14:11 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		create_socket(int client_socket)
{
	struct protoent	*proto;

	proto = getprotobyname("tcp");
	if (proto == 0)
	{
		RED;
		ft_putendl("Error to get proto");
		CANCEL;
		exit(3);
	}
	if ((client_socket = socket(AF_INET, SOCK_STREAM, proto->p_proto)) == -1)
	{
		RED;
		ft_putendl("Client: Error to create a new socket");
		CANCEL;
	}
	return (client_socket);
}

void	display_prompt(void)
{
	char	*user;

	user = getenv("USER");
	CYAN;
	write(1, "[", 1);
	write(1, user, ft_strlen(user));
	write(1, "]", 1);
	CANCEL;
	YELLOW;
	write(1, " ~>", 3);
	CANCEL;
}

int 	first_msg(char *buff)
{
	char	**tab;

	tab = NULL;
	tab = ft_strsplit(buff, '@');
	if (tab[1])
		return (1);
	return (0);
}

int 	check_list_member(char *buff)
{
	char	**tab;

	tab = ft_memalloc(ft_strlen(buff));
	tab = ft_strsplit(buff, '*');
	if (tab[1])
		return (1);
	return (0);
}

void	cut_list(char *list, t_ncurse *curs)
{
	char	**tab;
	int 	i;
	int 	y;

	wclear(curs->win_member);
	tab = NULL;
	i = 1;
	y = 2;
	tab = ft_strsplit(list, '*');
	while (tab[i])
	{
		tab[i] = ft_strtrim(tab[i]);
		mvwprintw(curs->win_member, y, 3, "%s", tab[i]);
		i++;
		y++;
	}
}

void	action(int client_socket, t_info_client *client, struct sockaddr_in server_info, struct hostent *host_server)
{
	fd_set			readfds;
	t_ncurse		*curs;
	int				y;
	char			buff[1024];
	char			**msg;
	(void)host_server;
	(void)server_info;

	curs = init_curses();
	y = 0;
	while (42)
	{
		usleep(150000);
		draw_irc(curs);
		FD_ZERO(&readfds);
		FD_SET(0, &readfds);
	    FD_SET(client_socket, &readfds);
	    ft_bzero(buff, 1024);
		if (select(client_socket +1, &readfds, NULL, NULL, NULL) == -1)
			ft_error_i("ERROR Select", 1);
		else
		{
			if (FD_ISSET(0, &readfds))
				y = send_mess(y, client_socket, curs, client);
	        if (FD_ISSET(client_socket, &readfds))
	        {
	        	mvwprintw(curs->win_chat, 10, 3, "%s", buff);
	        	if (recv(client_socket, &buff, 1024, 0) == -1)
	        		ft_error_i("Error recv", 4);
	        	if (first_msg(buff))
	        		updt_nickname(buff, client);
				else if (check_cmd_client(buff))
				{
					ft_putendl("ca passe!!");
					exec_cmd_client(buff, client, curs);
				}
				else
				{
					msg = ft_strsplit(buff, '$');
					y++;
					if (y == ((curs->row * 9 / 10) - 1))
					{
						wclear(curs->win_chat);
						y = 1;
					}
					if (ft_strcmp(msg[1], "SERVEUR") == 0)
						mvwprintw(curs->win_chat, y, 0, "-------- %s : %s --------", msg[1], msg[2]);
					else if (ft_strncmp(msg[2], WHO, 4) == 0)
						y--;
					else
						mvwprintw(curs->win_chat, y, 3, " %s say => %s", msg[1], msg[2]);
				}
	        }
		}
	}
}

void	connect_server(int cli_sock, struct sockaddr_in serv_inf, t_info_client *client, struct hostent *host_server)
{
	if ((connect(cli_sock, (const struct sockaddr *)&serv_inf,
		sizeof(serv_inf))) == -1)
	{
		RED;
		ft_putendl("Client: Error to connect server");
		CANCEL;
		exit(3);
	}
	else
	{
		GREEN;
		ft_putendl("Client: Connection to server was etablished");
		CANCEL;
		action(cli_sock, client, serv_inf, host_server);
	}
}

int		main(int ac, char **av, char **env)
{
	int						client_socket;
	struct sockaddr_in		server_info;
	struct hostent			*host_server;
	t_info_client			*client;

	if (env[0] == NULL)
		return (0);
	client = ft_memalloc(sizeof(t_info_client));
	client_socket = 0;
	check_input_client(ac);
	host_server = gethostbyname(av[1]);
	if (host_server == NULL)
	{
		RED;
		ft_putendl("Client: Error to initialise hostname");
		CANCEL;
		exit(3);
	}
	ft_memcpy(&server_info.sin_addr, host_server->h_addr,
		host_server->h_length);
	server_info.sin_port = atoi(av[2]);
	server_info.sin_family = AF_INET;
	client_socket = create_socket(client_socket);
	connect_server(client_socket, server_info, client, host_server);
	return (0);
}
