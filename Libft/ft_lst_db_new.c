/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_db_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 12:59:14 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:13:05 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_store			*ft_lst_db_new(char *value, int val)
{
	t_store		*new;

	new = (t_store *)malloc(sizeof(t_store));
	if (new)
	{
		if (value)
		{
			new->prev = NULL;
			new->val = val;
			new->value = (void *)value;
			new->next = NULL;
		}
		else
		{
			new->val = 0;
			new->value = NULL;
		}
		return (new);
	}
	return (NULL);
}
