/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 17:08:39 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:39:39 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	char	*tmp;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	tmp = ft_strnew(ft_strlen(s));
	while (s[i] != '\0')
	{
		tmp[i] = f(s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
