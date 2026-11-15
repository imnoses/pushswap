/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memset.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/16 21:08:19 by spuschma         #+#    #+#              */
/*   Updated: 2026/09/16 21:15:11 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	char	b;
	char	*r;
	size_t	i;

	r = s;
	b = c;
	i = -1;
	while (++i < n)
		r[i] = b;
	return (s);
}
