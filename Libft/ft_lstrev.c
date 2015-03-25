/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 17:47:23 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:34:47 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						ft_lstrev(t_list **alst)
{
	t_list					*new;
	t_list					*old_next;
	t_list					*old_current;

	new = NULL;
	old_current = *alst;
	while (old_current)
	{
		old_next = old_current->next;
		old_current->next = new;
		new = old_current;
		old_current = old_next;
	}
	*alst = new;
}
