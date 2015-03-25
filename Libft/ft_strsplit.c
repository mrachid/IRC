/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/30 10:58:41 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:41:01 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_word(char const *s, char c)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i - 1] == c) || (i == 0 && s[i] != c))
			j++;
		i++;
	}
	return (j);
}

static char		*ft_cpy_word(char const *s, char c)
{
	int			a;
	char		*tmp;

	a = 0;
	if (!s)
		return (NULL);
	while (s[a] != c && s[a] != '\0')
		a++;
	tmp = ft_strsub(s, 0, a);
	return (tmp);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**str;
	int		t;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	t = ft_get_word(s, c);
	str = (char**)malloc(sizeof(char*) * t + 1);
	while (s[i] != '\0')
	{
		if ((s[i] != c && s[i - 1] == c) || (i == 0 && s[i] != c))
		{
			str[j] = ft_cpy_word(&s[i], c);
			j++;
		}
		i++;
	}
	str[j] = NULL;
	return (str);
}
