/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_split.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/16 10:38:23 by spuschma         #+#    #+#              */
/*   Updated: 2026/09/16 11:10:53 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	get_size(char const *s, char c)
{
	size_t	ret;

	ret = 0;
	while (s[0])
	{
		if (s[0] != c && (s[1] == c || s[1] == '\0'))
			ret++;
		s++;
	}
	return (ret);
}

static size_t	next_c_or_end_idx(char const *s, char c)
{
	size_t	i;

	i = -1;
	while (s[++i] != c && s[i])
		;
	return (i);
}

static void	free_arr(char **arr, size_t size)
{
	while (size)
		free(arr[--size]);
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	n_str;
	char	**arr;
	size_t	i;
	size_t	next_c;

	n_str = get_size(s, c);
	arr = ft_calloc(n_str + 1, sizeof(char *));
	if (!arr)
		return (arr);
	i = -1;
	while (++i < n_str)
	{
		while (*s == c)
			s++;
		next_c = next_c_or_end_idx(s, c);
		arr[i] = malloc(next_c + 1);
		if (!arr[i])
			return (free_arr(arr, n_str + 1), NULL);
		ft_strlcpy(arr[i], s, next_c + 1);
		s += next_c + 1;
	}
	return (arr);
}
