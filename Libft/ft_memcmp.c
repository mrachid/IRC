/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 17:17:07 by mrachid           #+#    #+#             */
/*   Updated: 2013/11/27 14:41:05 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char	*tp1;
	unsigned const char	*tp2;
	size_t				i;

	i = 0;
	tp1 = s1;
	tp2 = s2;
	if (n == 0)
		return (0);
	while (tp1[i] == tp2[i] && i + 1 < n && tp1[i] != '\0' && tp2[i] != '\0')
		i++;
	if (tp1[i] - tp2[i] == 0)
		return (0);
	return (tp1[i] - tp2[i]);
}
