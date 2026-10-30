/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   helpers.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/28 14:53:03 by spuschma         #+#    #+#              */
/*   Updated: 2026/10/28 17:19:47 by spuschma        ###   ########.fr        */
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

void	exit_if(int condition, t_data *s, char *message)
{
	if (!condition)
		return ;
	if (message)
		ft_putendl_fd(message, 2);
	if (s)
	{
		free(s->a.arr);
		free(s->b.arr);
		free(s);
	}
	exit(1);
}
