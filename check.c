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

int		check_cmd_client(char *buff)
{
	char	**msg;

	msg = NULL;
	msg = ft_strsplit(buff, '$');
	if (msg[2])
	{
		if (ft_strncmp(msg[2], UPDATE_NICKNAME, ft_strlen(UPDATE_NICKNAME)) == 0
			|| ft_strncmp(msg[2], JOIN_CHANNEL, ft_strlen(JOIN_CHANNEL)) == 0
			|| ft_strncmp(buff, WHO, ft_strlen(WHO)) == 0
			|| ft_strncmp(msg[2], MSG, ft_strlen(MSG)) == 0
			|| ft_strncmp(msg[2], LEAVE, ft_strlen(LEAVE)) == 0
			|| ft_strncmp(msg[2], DECO, ft_strlen(DECO)) == 0)
			// || ft_strncmp(msg[2], CO, ft_strlen(CO)) == 0)
			return (1);
	}
	else if (ft_strncmp(msg[1], WHO, ft_strlen(WHO)) == 0)
		return 1;
	return (0);
}

int		check_cmd(char *buff)
{
	buff = ft_strtrim(buff);
	if (ft_strncmp(buff, UPDATE_NICKNAME, ft_strlen(UPDATE_NICKNAME)) == 0
			|| ft_strncmp(buff, JOIN_CHANNEL, ft_strlen(JOIN_CHANNEL)) == 0
			|| ft_strncmp(buff, WHO, ft_strlen(WHO)) == 0
			|| ft_strncmp(buff, MSG, ft_strlen(MSG)) == 0
			|| ft_strncmp(buff, LEAVE, ft_strlen(LEAVE)) == 0
			|| ft_strncmp(buff, DECO, ft_strlen(DECO)) == 0
			|| ft_strncmp(buff, CO, ft_strlen(CO)) == 0)
		return (1);
	return (0);
}
