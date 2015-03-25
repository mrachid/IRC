/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/23 10:31:01 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:48:16 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s1)
{
	char	*str;

	str = (char *)malloc(ft_strlen(s1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	else
		ft_strcpy(str, s1);
	return (str);
}
