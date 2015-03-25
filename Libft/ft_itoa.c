/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/28 11:43:48 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:34:01 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			get_size(int n)
{
	int				len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
		len++;
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char				*ft_itoa(int n)
{
	char			*tmp;
	int				a;
	int				b;

	b = get_size(n);
	tmp = ft_strnew(b);
	a = 1;
	if (n < 0)
	{
		a = -1;
		tmp[0] = '-';
	}
	if (n == 0)
		tmp[0] = '0';
	if (b > 0)
		b = b - 1;
	while (n != 0)
	{
		tmp[b] = a * (n % 10) + '0';
		n = n / 10;
		b--;
	}
	return (tmp);
}
