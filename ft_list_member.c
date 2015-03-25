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

int		empty_list(t_lst_member *list)
{
	if (list == NULL)
		return (0);
	return (1);
}

void	ft_display_member(t_lst_member *list)
{
    t_lst_member	*tmp;

    tmp = list;
 	while (tmp != NULL)
    {
    	GREEN;
    	tmp = tmp->next;
        ft_putendl(tmp->nickname);
        ft_putnbr(tmp->socket);
        ft_putendl(" ");
        ft_putendl(tmp->chanel);
        ft_putendl("--------------");
        CANCEL;
        tmp = tmp->next;
    }
}

void	ft_add_member(t_lst_member *list, char *nickname,
    char *chanel, int socket)
{
    t_lst_member	*new_membre;
	new_membre = (t_lst_member *)malloc(sizeof(t_lst_member));
	new_membre->nickname = nickname;
	new_membre->chanel = chanel;
	new_membre->socket = socket;
	new_membre->next = NULL;

	while (list->next != NULL)
		list = list->next;
	list->next = new_membre;
}

t_lst_member	*creat_new_list(t_lst_member *membre, t_irc *irc)
{
	membre = (t_lst_member *)malloc(sizeof(t_lst_member));
	membre->nickname = "Sock Server";
	membre->chanel = PUBLIC;
	membre->socket = irc->serv_sock;
	membre->next = NULL;

	return (membre);
}

int				ft_size_socket(t_lst_member *list)
{
    t_lst_member	*tmp;
    int				i;

    tmp = list;
	i = 0;
	while (tmp != NULL)
    {
        i++;
        tmp = tmp->next;
    }
    return (i);
}
