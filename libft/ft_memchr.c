/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memchr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/13 19:24:21 by spuschma         #+#    #+#              */
/*   Updated: 2026/09/13 20:55:00 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*p;

	if (n == 0)
		return (NULL);
	p = (char *)s;
	while (--n && *p != (char)c)
		p++;
	if (*p == (char)c)
		return ((void *)p);
	return (NULL);
}
