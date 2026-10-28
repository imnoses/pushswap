/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   helpers.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/28 14:53:03 by spuschma         #+#    #+#              */
/*   Updated: 2026/10/28 14:55:18 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

int	ft_isws(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

// Exits with error message on fail
int	error_throwing_atoi(const char *nptr, char *error_message)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while (ft_isws(*nptr))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr))
	{
		result = (result * 10) + *nptr - '0';
		nptr++;
	}
	if (!*nptr)
		return (result * sign);
	ft_putendl_fd(error_message, 2);
	exit(1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = -1;
	while (s1[++i] && s1[i] == s2[i])
		;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	exit_if(int condition, t_stack_collection *s, char *message)
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
