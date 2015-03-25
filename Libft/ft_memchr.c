/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 14:51:29 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:43:28 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*tmp;
	size_t				i;

	tmp = s;
	i = 0;
	while (i < n && (unsigned char)c != tmp[i])
		i++;
	if (i < n && (unsigned char)c == tmp[i])
		return ((void*)(s + i));
	return (NULL);
}
