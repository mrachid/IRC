/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 15:17:15 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:46:40 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	check;
	size_t	min;

	check = size - ft_strlen(dst) - 1;
	if (size < ft_strlen(dst))
		min = size;
	else
		min = ft_strlen(dst);
	if ((int)check > 0)
		ft_strncat(dst, src, check);
	return (ft_strlen(src) + min);
}
