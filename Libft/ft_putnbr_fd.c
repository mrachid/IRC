/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrachid <mrachid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/01 15:25:18 by mrachid           #+#    #+#             */
/*   Updated: 2014/04/16 13:37:16 by mrachid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_rec(int n, int fd)
{
	char		num;

	if (n < -9)
		ft_putnbr_rec(n / 10, fd);
	num = '0' - n % 10;
	write(fd, &num, 1);
}

void			ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	else
		n = n * (-1);
	ft_putnbr_rec(n, fd);
}
