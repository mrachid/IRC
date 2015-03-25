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

char	*get_user_name(char **env)
{
	char	**user;
	int 	i;

	user = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "USER", 4) == 0)
		{
			user = ft_strsplit(env[i], '=');
			return (user[1]);
		}
		i++;
	}
	return (NULL);
}

void	check_input_server(int ac)
{
	if (ac != 2)
	{
		RED;
		ft_putendl("Please enter port server");
		CANCEL;
		exit(3);
	}
}

int 	get_max_socket(int sock, int sockmax)
{
	if (sockmax < sock)
		return (sock);
	return (sockmax);
}

int 	ft_strlen_tab(int *tab)
{
	int 	i;

	i = 0;
	while (tab[i] != 0)
		i++;
	return i;
}