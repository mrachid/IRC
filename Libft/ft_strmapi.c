/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 18:32:08 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:39:46 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	int		i;

	if (!s || !f)
		return (NULL);
	i = 0;
	tmp = ft_strnew(ft_strlen(s));
	while (s[i] != '\0')
	{
		tmp[i] = f(i, s[i]);
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
