/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_putnbr_fd.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/16 20:40:50 by spuschma         #+#    #+#              */
/*   Updated: 2026/09/16 21:03:48 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_fd_internal(long l, int fd)
{
	if (l > 9)
		ft_putnbr_fd_internal(l / 10, fd);
	ft_putchar_fd((l % 10) + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long	l;

	l = n;
	if (l < 0)
	{
		ft_putchar_fd('-', fd);
		l = -l;
	}
	if (l > 9)
		ft_putnbr_fd_internal(l / 10, fd);
	ft_putchar_fd((l % 10) + '0', fd);
}
