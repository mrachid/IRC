/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/11 16:26:36 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:34:38 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new)
	{
		if (content)
		{
			new->content_size = content_size;
			new->content = (void *)content;
			new->next = NULL;
		}
		else
		{
			new->content_size = 0;
			new->content = NULL;
		}
		return (new);
	}
	return (NULL);
}
