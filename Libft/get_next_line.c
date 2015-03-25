/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/27 10:30:05 by mrachid           #+#    #+#             */
/*   Updated: 2014/05/08 15:10:51 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int		fct_strlen(char *str)
{
	int			i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
		i++;
	return (i);
}

static char		*fct_strdup(char *str)
{
	int			i;
	char		*new;

	i = 0;
	new = NULL;
	if (str == NULL)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * fct_strlen(str) + 1)))
		return (NULL);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static char		*fct_strcat(char *s1, char *s2)
{
	int			i;
	int			j;
	int			len;
	char		*new;

	i = 0;
	j = 0;
	len = (fct_strlen(s1) + fct_strlen(s2) + 1);
	if (!(new = (char *)malloc(sizeof(char) * len)))
		return (NULL);
	if (s1 != NULL)
	{
		while (s1[i] != '\0')
		{
			new[i] = s1[i];
			i++;
		}
	}
	if (s2 != NULL)
	{
		while (s2[j] != '\0')
			new[i++] = s2[j++];
	}
	new[i] = '\0';
	return (new);
}

static int		ft_search(char *tmp, char **tab, char **line)
{
	int			i;

	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\n' || tmp[i + 1] == 26)
		{
			tmp[i++] = '\0';
			*tab = NULL;
			*tab = fct_strdup(&tmp[i]);
			*line = fct_strdup(tmp);
			free(tmp);
			tmp = NULL;
			return (1);
		}
		i++;
	}
	*tab = NULL;
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	static char	*tab = "";
	char		*tmp;
	char		*buff;
	int			ret;

	tmp = NULL;
	buff = NULL;
	if (!(buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	while ((ret = read(fd, buff, BUFF_SIZE)) > 0 || tab)
	{
		if (ret == -1)
			return (-1);
		buff[ret] = 0;
		tmp = fct_strcat(tmp, tab);
		tmp = fct_strcat(tmp, buff);
		if (ft_search(tmp, &tab, line) == 1)
			return (1);
	}
	if (tmp && *tmp && ret == 0)
	{
		*line = fct_strdup(tmp);
		return (1);
	}
	return (0);
}
