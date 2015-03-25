/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 13:21:57 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:46:55 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && i < n)
	{
		if (ft_strncmp(s1 + i, s2, ft_strlen(s2)) == 0
				&& ft_strlen(s2) + i <= n)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
