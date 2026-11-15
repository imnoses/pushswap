/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_calloc.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/13 21:57:22 by spuschma         #+#    #+#              */
/*   Updated: 2026/09/18 11:40:40 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_calloc(size_t n, size_t size)
{
	char	*p;
	size_t	s;

	s = n * size;
	if (n != 0 && s / n != size)
		return (0);
	p = malloc(n * size);
	if (!p)
		return (p);
	ft_bzero(p, n * size);
	return (p);
}
