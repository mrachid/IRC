/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_db_addend.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 12:57:53 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:12:52 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lst_db_addend(t_store **alst, t_store *elem)
{
	t_store		*temp;

	if (elem)
	{
		if (alst && *alst)
		{
			temp = *alst;
			while (temp->next)
				temp = temp->next;
			elem->prev = temp;
			temp->next = elem;
		}
		else
			*alst = elem;
	}
}
