//* ************************************************************************** */
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

void	check_input_client(int ac)
{
	if (ac != 3)
	{
		RED;
		ft_putendl("Please Enter Hostname and port number to connect server");
		CANCEL;
		exit(3);
	}
}

char	*trim_input(char *str)
{
	char	*tmp;

	tmp = ft_memalloc(ft_strlen(str) + 1);
	ft_bzero(tmp, (ft_strlen(str) + 1));
	tmp = ft_strtrim(str);
	return (tmp);
}

void	update_nickname(char *name, int client_socket)
{
	char	*mess;

	if (name != NULL)
	{
		mess = ft_strtrim(name);
		if (send(client_socket, name, 1024, 0) == -1)
			ft_error_i("Error send", 1);
	}
}

void	env_server(char *buff, int client_socket)
{
	if (send(client_socket, buff, ft_strlen(buff), 0) == -1)
		ft_error_i("Error send", 1);
}

// int		check_cmd_client(char *buff)
// {
// 	char	**tab;

// 	tab = ft_strsplit(buff, ' ');
// 	tab[0] = ft_strtrim(tab[0]);
// 	if (ft_strncmp(tab[0], "/nick", 5) == 0
// 		|| ft_strncmp(tab[0], "/join", 5) == 0
// 		|| ft_strncmp(tab[0], "/who", 4) == 0
// 		|| ft_strncmp(tab[0], "/msg", 4) == 0
// 		|| ft_strncmp(tab[0], "/quit", 5) == 0)
// 		return (1);
// 	return (0);
// }

int 	send_mess(int y, int client_socket, t_ncurse *curs, t_info_client *client)
{
	char 		buff[1024];
	int 		auth;

	auth = 0;
	ft_bzero(buff, 1024);
	if (!wgetstr(curs->win_term, buff))
	{
		if (check_cmd(buff))
			env_server(buff, client_socket);
		else
		{
			auth = 1;
			y++;
		}
	}
	if (y == ((curs->row * 9 / 10) - 1))
	{
		wclear(curs->win_chat);
		y = 1;
	}
	if (auth)
	{
		mvwprintw(curs->win_chat, y, 3, " %s say => %s", client->nickname, buff);
		if (send(client_socket, buff, 1024, 0) == -1)
			ft_error_i("Error send", 1);
    }
    return (y);
}

void	exec_cmd_client(char *buff, t_info_client *client, t_ncurse *curs) // finir ici les commandes
{
	char	**tab;
	char	**cmd;
	char	**tab1;
	char	*env;
	int 	i;
	int 	y;
	int 	j;

	i = 1;
	y = 2;
	j = 2;
	tab = ft_strsplit(buff, '$');
	tab1 = ft_strsplit(tab[1], '|');
	if (tab[2])
	{
		cmd = ft_strsplit(tab[2], ' ');
		cmd[0] = ft_strtrim(tab[0]);
		if (ft_strncmp(cmd[0], UPDATE_NICKNAME, ft_strlen(UPDATE_NICKNAME)) == 0)
		{
			client->nickname = ft_memalloc(ft_strlen(cmd[1]));
			client->nickname = cmd[1];
		}
		if (ft_strncmp(cmd[0], MSG, ft_strlen(MSG)) == 0)
		{
			env = ft_memalloc(1024);
			while (cmd[j])
			{
				env = ft_strjoin(env, cmd[j]);
				env = ft_strjoin(env, " ");
				j++;
			}
			// mvwprintw(curs->win_member, 12, 3, "%s", env);
		}
	}
	else if ((tab[1]) && (!tab[2]))
	{
		wrefresh(curs->win_member);
		while (tab1[i])
		{
			mvwprintw(curs->win_member, y, 3, "%s", tab1[i]);
			i++;
			y++;
		}
	}
}

void	updt_nickname(char *buff, t_info_client *client) // erreur segfault
{
	char	**tab;

	tab = NULL;
	tab = ft_strsplit(buff, '@');
	client->nickname = ft_memalloc(ft_strlen(tab[1]));
	client->nickname = tab[1];
}
