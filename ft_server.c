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

static void		ft_server_addr(t_irc *irc, char **env, char **av)
{
	struct sockaddr_in		server_addr;

	server_addr.sin_port = atoi(av[1]);
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	irc->serv_sock = init_server(create_socket(irc->serv_sock), server_addr);
	irc->nick_def = get_user_name(env);

}

static t_lst_member	*ft_list_member(t_lst_member *member, t_irc *irc)
{
	t_lst_member			*tmp;

	tmp = member;
	FD_ZERO(&irc->readfds);
	while (tmp != NULL)
	{
		if (tmp->socket != 0)
		{
			FD_SET(tmp->socket, &irc->readfds);
			irc->sockmax = get_max_socket(tmp->socket, irc->sockmax);
		}
		tmp = tmp->next;
	}
	return (tmp);
}

static void		ft_client_addr(t_lst_member *member, t_irc *irc)
{
	struct sockaddr_in		cli_addr;

	if (select(irc->sockmax +1, &irc->readfds, NULL, NULL, NULL) == -1)
		ft_error_i("ERROR select", 3);
	if (FD_ISSET(irc->serv_sock, &irc->readfds))
	{
		irc->cli_sock = wait_connect(irc->serv_sock, irc->cli_sock, cli_addr);
		ft_add_member(member, irc->nick_def, PUBLIC, irc->cli_sock);
		irc->name = ft_strjoin("1@", irc->nick_def);
		if (send(irc->cli_sock, irc->name, ft_strlen(irc->name), 0) == -1)
			ft_error_i("Error to send", 1);
	}
}

static void		ft_hearts_server(t_irc *irc, t_lst_member *member,
	t_lst_member *tmp)
{
	t_lst_member			*tmp2;

	ft_bzero(irc->buff, ft_strlen(irc->buff));
	if (FD_ISSET(tmp->socket, &irc->readfds))
	{
		if (recv(tmp->socket, &irc->buff, 1024, 0) == -1)
			ft_error_i("Error to received message", 4);
		if (check_cmd(irc->buff))
			exec_cmd_sev(irc->buff, tmp->socket, member);			
		tmp2 = member;
		tmp2 = tmp2->next;
		while ((ft_size_socket(tmp2)) > 0)
		{
			irc->msg = custom_buffer(irc->buff, tmp->socket, member);
			if ((tmp2->socket != tmp->socket) &&
				(ft_strcmp(tmp2->chanel, tmp->chanel) == 0))
			{
				if (send(tmp2->socket, irc->msg, 1024, 0) == -1)
					ft_error_i("Error to send", 1);
			}
			tmp2 = tmp2->next;
		}
	}
}

int		main(int ac, char **av, char **env)
{
	t_irc					*irc;
	t_lst_member			*member;
	t_lst_member			*tmp;

	if (env[0] == NULL)
		return (0);
	member = ft_memalloc(sizeof(t_lst_member));
	irc = ft_memalloc(sizeof(t_irc));
	check_input_server(ac);
	ft_server_addr(irc, env, av);
	member = creat_new_list(member, irc);
	while (42)
	{
		tmp = ft_list_member(member, irc);
		ft_client_addr(member, irc);
		tmp = member;
		tmp = tmp->next;
		while ((ft_size_socket(tmp)) > 0)
		{
			ft_hearts_server(irc, member, tmp);
			tmp = tmp->next;
		}
	}
	close(irc->serv_sock);
	return (0);
}
