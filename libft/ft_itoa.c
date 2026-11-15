/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_itoa.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/16 12:09:38 by spuschma         #+#    #+#              */
/*   Updated: 2026/09/16 12:42:41 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*buf;
	int		i;
	char	*ret;
	long	nbr;

	buf = malloc(12);
	if (!buf)
		return (NULL);
	nbr = n;
	if (n < 0)
		nbr = -nbr;
	i = 12;
	buf[--i] = '\0';
	if (nbr == 0)
		buf[--i] = '0';
	while (--i && nbr)
	{
		buf[i] = (nbr % 10) + '0';
		nbr = nbr / 10;
	}
	if (n < 0)
		buf[i--] = '-';
	ret = ft_strdup(buf + i + 1);
	free(buf);
	return (ret);
}
