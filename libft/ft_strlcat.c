/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strlcat.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/13 16:24:13 by spuschma         #+#    #+#              */
/*   Updated: 2026/09/13 16:24:13 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dst_size;

	dst_size = -1;
	while (++dst_size < size && dst[dst_size])
		;
	return (dst_size + ft_strlcpy(dst + dst_size, src, size - dst_size));
}
