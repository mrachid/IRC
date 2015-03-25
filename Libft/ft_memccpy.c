/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 16:46:59 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:43:05 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	unsigned char		*tmp1;
	const unsigned char	*tmp2;
	size_t				i;

	tmp1 = s1;
	tmp2 = s2;
	i = 0;
	while (i < n && (unsigned char)c != tmp2[i])
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	if (i != n)
	{
		tmp1[i] = c;
		return ((void*)tmp1 + i + 1);
	}
	else
		return (NULL);
}
