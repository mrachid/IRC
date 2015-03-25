/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:17:47 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:43:38 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;
	size_t			i;

	i = 0;
	tmp = b;
	while (i < len)
	{
		tmp[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
