/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 11:37:10 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:40:02 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && i + 1 < n && s1[i] != '\0' && s2[i] != '\0')
		i++;
	if (s1[i] - s2[i] == 0)
		return (0);
	if (s1[i] - s2[i] < 0)
		return (-1);
	else
		return (1);
}
