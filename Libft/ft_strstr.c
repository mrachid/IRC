/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 11:31:35 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:47:16 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	while (*s1)
	{
		if (ft_strncmp(s1, s2, ft_strlen(s2)) == 0)
			return ((char*)s1);
		s1++;
	}
	if (*s2 == '\0')
		return ((char*)s1);
	return (NULL);
}
