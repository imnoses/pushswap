/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   splitws.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/28 14:04:42 by spuschma         #+#    #+#              */
/*   Updated: 2026/10/28 14:56:46 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

static size_t	get_size(char const *s)
{
	size_t	ret;

	ret = 0;
	while (s[0])
	{
		if (!ft_isws(s[0]) && (ft_isws(s[1]) || s[1] == '\0'))
			ret++;
		s++;
	}
	return (ret);
}

static size_t	next_ws_or_end_idx(char const *s)
{
	size_t	i;

	i = -1;
	while (!ft_isws(s[++i]) && s[i])
		;
	return (i);
}

static void	free_arr(char **arr, size_t size)
{
	while (size)
		free(arr[--size]);
	free(arr);
}

char	**splitws(char const *s)
{
	size_t	n_str;
	char	**arr;
	size_t	i;
	size_t	next_ws;

	n_str = get_size(s);
	arr = ft_calloc(n_str + 1, sizeof(char *));
	if (!arr)
		return (arr);
	i = -1;
	while (++i < n_str)
	{
		while (ft_isws(*s))
			s++;
		next_ws = next_ws_or_end_idx(s);
		arr[i] = malloc(next_ws + 1);
		if (!arr[i])
			return (free_arr(arr, n_str + 1), NULL);
		ft_strlcpy(arr[i], s, next_ws + 1);
		s += next_ws + 1;
	}
	return (arr);
}
