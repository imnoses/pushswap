/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strmapi.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/16 20:16:17 by spuschma         #+#    #+#              */
/*   Updated: 2026/09/16 20:21:49 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*ret;
	unsigned int	i;

	len = ft_strlen(s);
	ret = malloc(len + 1);
	if (!ret)
		return (ret);
	ret[len] = 0;
	i = -1;
	while (s[++i])
		ret[i] = (*f)(i, s[i]);
	return (ret);
}
