/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_db_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 12:56:14 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:12:39 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_db_add(t_store **alst, t_store *elem)
{
	if (elem)
	{
		if (alst && *alst)
		{
			(*alst)->prev = elem;
			elem->next = *alst;
		}
		*alst = elem;
	}
}
