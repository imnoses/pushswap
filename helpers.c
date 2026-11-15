/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   helpers.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/28 14:53:03 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/15 22:26:49 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <limits.h>
#include <stdlib.h>

int	ft_isws(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

// Returns 0 on fail
char	status_atoi(const char *nptr, int *result)
{
	int		sign;
	long	l_res;

	l_res = 0;
	sign = 1;
	while (ft_isws(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		if (*(nptr++) == '-')
			sign = -1;
	if (!*nptr)
		return (0);
	while (ft_isdigit(*nptr))
	{
		l_res = (l_res * 10) + *nptr - '0';
		nptr++;
		if (l_res * sign > INT_MAX || l_res * sign < INT_MIN)
			return (0);
	}
	if (*nptr)
		return (0);
	*result = l_res * sign;
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = -1;
	while (s1[++i] && s1[i] == s2[i])
		;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	free(data->a.arr);
	free(data->b.arr);
	free(data->ops.buf);
	free(data);
}

void	exit_if(int condition, t_data *data)
{
	if (!condition)
		return ;
	ft_putendl_fd("Error", 2);
	free_data(data);
	exit(1);
}

int	index_array(int *arr, size_t size)
{
	int		*rank;
	size_t	i;
	size_t	j;

	rank = ft_calloc(size, sizeof(int));
	if (!rank)
		return (0);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (j != i && arr[j] == arr[i])
				return (free(rank), 0);
			if (arr[j] < arr[i])
				rank[i]++;
		}
	}
	i = -1;
	while (++i < size)
		arr[i] = rank[i];
	return (free(rank), 1);
}
