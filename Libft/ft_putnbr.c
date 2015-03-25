/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:30:16 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:36:58 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_putnbr_rec(int n)
{
	char			num;

	if (n < -9)
		ft_putnbr_rec(n / 10);
	num = '0' - n % 10;
	write(1, &num, 1);
}

void				ft_putnbr(int n)
{
	if (n < 0)
		write(1, "-", 1);
	else
		n = n * (-1);
	ft_putnbr_rec(n);
}
