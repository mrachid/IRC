/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 12:34:44 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 15:28:56 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *s1, const void *s2, size_t n)
{
	void	*temp;

	if (n == 0)
		return (s1);
	temp = malloc(n);
	if (temp != NULL)
	{
		ft_memcpy(temp, s2, n);
		ft_memcpy(s1, temp, n);
		free(temp);
		temp = NULL;
	}
	return (s1);
}
