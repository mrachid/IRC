/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:35:28 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:39:15 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*tmp;

	if (s1 && s2)
	{
		tmp = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (!tmp)
			return (NULL);
		ft_strcpy(tmp, s1);
		ft_strcat(tmp, s2);
		return (tmp);
	}
	return (NULL);
}
