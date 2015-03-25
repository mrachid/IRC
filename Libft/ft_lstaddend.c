/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/15 08:43:07 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:34:27 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstaddend(t_list **alst, t_list *new)
{
	t_list	*temp;

	if (new)
	{
		if (alst && *alst)
		{
			temp = *alst;
			while (temp->next)
				temp = temp->next;
			temp->next = new;
		}
		else
			*alst = new;
	}
}
