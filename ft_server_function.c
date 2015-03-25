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

int		create_socket(int server_socket)
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
	if ((server_socket = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
	{
		RED;
		ft_putendl("Serveur: Error to create a new socket");
		CANCEL;
		exit(3);
	}
	return (server_socket);
}

int		init_server(int server_socket, struct sockaddr_in server_addr)
{
	if ((bind(server_socket, (struct sockaddr *)&server_addr,
		sizeof(server_addr))) == -1)
	{
		RED;
		ft_putendl("Serveur: Error to bind server");
		CANCEL;
	}
	if ((listen(server_socket, 42)) == -1)
	{
		RED;
		ft_putendl("Serveur: Error to listen socket");
		CANCEL;
	}
	return (server_socket);
}

int		wait_connect(int s_sock, int c_s, struct sockaddr_in c_adr)
{
	socklen_t	length_addr_client;
	int			ip_client;

	length_addr_client = sizeof(c_adr);
	if ((c_s = accept(s_sock, (struct sockaddr *)&c_adr,
		&length_addr_client)) == -1)
		ft_putendl("Error to accept connexion");
	else
	{
		GREEN;
		ip_client = c_adr.sin_addr.s_addr;
		ft_putstr("[");
		ft_putnbr(ip_client);
		ft_putstr("] ");
		ft_putendl("Client was connected");
		CANCEL;
	}
	return (c_s);
}

char	*custom_buffer(char buff[1024], int sender, t_lst_member *member)
{
	char			*msg;
	char			*name;
	t_lst_member	*tmp;
	int 			i;

	msg = NULL;
	tmp = member;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->socket == sender)
			name = ft_strdup(tmp->nickname);
		tmp = tmp->next;
	}
	msg = ft_memalloc((ft_strlen(buff)) + (ft_strlen(name)));
	msg = ft_strjoin(msg, SENDER);
	msg = ft_strjoin(msg, name);
	msg = ft_strjoin(msg, "$");
	msg = ft_strjoin(msg, buff);
	msg = ft_strtrim(msg);
	return (msg);
}