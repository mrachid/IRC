/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 17:22:36 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:47:35 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == ' ')
		return (1);
	return (0);
}

char			*ft_strtrim(const char *s)
{
	size_t		i;
	size_t		j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_strlen(s) - 1;
	while (ft_isspace(s[i]))
		i++;
	while (ft_isspace(s[j]) && j > 0)
		--j;
	if ((int)(j - i + 1) <= 0)
		return (ft_strsub(s, i, 0));
	return (ft_strsub(s, i, j - i + 1));
}
