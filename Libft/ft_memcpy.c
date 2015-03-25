/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 11:32:16 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:35:50 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*tmp1;
	const char		*tmp2;

	tmp1 = s1;
	tmp2 = s2;
	i = 0;
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		i++;
	}
	return (s1);
}
