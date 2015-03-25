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

void	exec_cmd_sev(char *buff, int client_socket, t_lst_member *member)
{
	char 	**cut;

	cut = ft_strsplit(buff, ' ');
	cut[0] = ft_strtrim(cut[0]);
	if (ft_strcmp(cut[0], WHO) == 0)
		send_member_lst(client_socket, member);
	else if (ft_strcmp(cut[0], LEAVE) == 0)
		exit_channel(client_socket, buff, member);
	else
	{
		if ((cut[1] = ft_strtrim(cut[1])) != NULL)
		{
			if (strcmp(cut[0], UPDATE_NICKNAME) == 0)
				upd_nick(cut[1], client_socket, member);
			else if (strcmp(cut[0], JOIN_CHANNEL) == 0)
				join_channel(cut[1], client_socket, member);
			else if (strcmp(cut[0], WHO) == 0)
				send_member_lst(client_socket, member);
			else if (strcmp(cut[0], MSG) == 0)
			 	send_private_msg(client_socket, buff, member);
		}
	}
}

void	send_member_lst(int client, t_lst_member *member)
{
	char	*str;

	str = get_list_member(member);
	if (send(client, str, ft_strlen(str), 0) == -1)
		ft_error_i("Error to send", 1);
}

char	*get_list_member(t_lst_member *member)
{
	t_lst_member	*tmp;
	char 			*str;

	tmp = member;
	tmp = tmp->next;
	str = ft_memalloc((sizeof(member)) + (ft_strlen(WHO)));
	str = ft_strjoin(str, SENDER);
	str = ft_strjoin(str, WHO);
	while (tmp != NULL)
	{
		str = ft_strjoin(str, "|");
		str = ft_strjoin(str, tmp->nickname);
		tmp = tmp->next;
	}
	return (str);
}


void	upd_nick(char *name, int client_socket, t_lst_member *member)
{
	t_lst_member	*tmp;
	char 			*str;

	str = NULL;
	if (name != NULL)
	{
		tmp = member;
		while (tmp != NULL)
		{
			if (tmp->socket == client_socket)
			{
				tmp->nickname = ft_strdup(name);
				str = ft_strjoin("1@", name);
				if (send(client_socket, str, ft_strlen(str), 0) == -1)
					ft_error_i("Error to send", 1);
			}
			tmp = tmp->next;
		}
	}
}

void	 	send_private_msg(int client_socket, char *buff,t_lst_member *member)
{
	t_lst_member 	*tmp;
	t_lst_member 	*tmp1;
	char			*str;
	char			**msg;
	int 			i;

	i = 2;
	str = ft_memalloc(ft_strlen(buff) + ft_strlen(SENDER) + 1);
	tmp = member;
	tmp1 = member;
	str = ft_strjoin(str, SENDER);
	msg = ft_strsplit(buff, ' ');
	while (tmp != NULL)
	{
		if (tmp->socket == client_socket)
		{
			str = ft_strjoin(str, tmp->nickname);
			while (tmp1 != NULL)
			{
				if (ft_strcmp(tmp1->nickname, (msg[1] = ft_strtrim(msg[1]))) == 0)
				{
					str = ft_strjoin(str, "$");
					while (msg[i])
					{
						msg[i] = ft_strtrim(msg[i]);
						str = ft_strjoin(str, " ");
						str = ft_strjoin(str, msg[i]);
						i++;
					}
					if (send(tmp1->socket, str, ft_strlen(str), 0) == -1)
						ft_error_i("Error to send", 1);
				}
				tmp1 = tmp1->next;
			}
		}
		tmp = tmp->next;
	}
}
