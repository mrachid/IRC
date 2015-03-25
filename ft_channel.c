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

int 	check_channel(char *channel)
{
	if(ft_strcmp(channel, PUBLIC) == 0
		|| ft_strcmp(channel, B2C) == 0
		|| ft_strcmp(channel, HEC) == 0
		|| ft_strcmp(channel, PEDAGO) == 0
		|| ft_strcmp(channel, STAFF) == 0)
		return (1);
	else
		return (0);
}

void	join_channel(char *channel, int client_socket, t_lst_member *member)
{
	t_lst_member	*tmp;
	
	if(check_channel(channel))
	{		
		tmp = member;
		while (tmp != NULL)
		{
			if (tmp->socket == client_socket)
				tmp->chanel = ft_strdup(channel);
			tmp = tmp->next;
		}
	}
	else
	{
		channel = ft_strjoin(channel, SENDER);
		channel = ft_strjoin(channel, "SERVEUR$Erreur sur le channel");
		if (send(client_socket, channel, ft_strlen(channel), 0) == -1)
			ft_error_i("Error to send", 1);
	}
}

void	exit_channel(int client_socket, char *buff, t_lst_member * member)
{
	t_lst_member	*tp;
	char			**str;

	str = ft_strsplit(buff, ' ');
	tp = member;	
	while (tp != NULL)
	{
		if (str[1] && check_channel(str[1]))
		{			
			if (tp->socket == client_socket &&
				ft_strcmp(str[1], tp->chanel) == 0)
				tp->chanel = ft_strdup(PUBLIC);
		
		}
		else if (ft_strcmp(buff, LEAVE) == 0 && tp->socket == client_socket)
			tp->chanel = ft_strdup(PUBLIC);       
		tp = tp->next;
	}
}
