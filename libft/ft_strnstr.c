/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strnstr.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/13 21:11:38 by spuschma         #+#    #+#              */
/*   Updated: 2026/09/16 21:36:31 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	l_size;
	size_t	j;

	l_size = ft_strlen(little);
	if (l_size == 0)
		return ((char *)big);
	if (len < 1)
		return (NULL);
	i = 0;
	while (big[i] && i + l_size <= len)
	{
		j = 0;
		while (big[i] && big[i + j] == little[j] && j < l_size)
			j++;
		if (j == l_size)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
