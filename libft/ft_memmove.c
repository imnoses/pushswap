/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memmove.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/13 16:24:13 by spuschma         #+#    #+#              */
/*   Updated: 2026/09/18 11:42:40 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;

	if (!src || !dest)
		return (dest);
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	s = src;
	d = dest;
	while (n--)
		d[n] = s[n];
	return (dest);
}
