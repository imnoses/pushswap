/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_substr.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/16 09:52:03 by spuschma         #+#    #+#              */
/*   Updated: 2026/09/16 10:10:50 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*ret;

	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_calloc(1, sizeof(char)));
	s += start;
	s_len -= start;
	if (s_len < len)
		len = s_len;
	ret = malloc(sizeof(char) * len + 1);
	if (!ret)
		return (ret);
	ft_strlcpy(ret, s, len + 1);
	return (ret);
}
