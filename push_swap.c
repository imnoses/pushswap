/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/26 17:53:16 by spuschma         #+#    #+#              */
/*   Updated: 2026/10/26 22:40:28 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack
{
	int				*arr;
	size_t			cap;
	size_t			head;
	size_t			size;
}					t_stack;

typedef struct s_stack_collection
{
	t_stack			a;
	t_stack			b;
}					t_stack_collection;

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

// Exits with error message on fail
int	error_throwing_atoi(const char *nptr, t_stack_collection *s)
{
	int	sign;
	int	result;

	result = 0;
	sign = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\f'))
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
	exit_if(*nptr, s, "One of the numbers is malformed!");
	return (result * sign);
}

t_stack_collection	*init_stacks(int argc, char **argv, char **flag)
{
	int					i;
	t_stack_collection	*s;

	s = ft_calloc(1, sizeof(t_stack_collection));
	if (!s)
		exit(1);
	s->a.arr = malloc((argc - 1) * sizeof(int)); // Might be too big by 1. Meh
	s->b.arr = malloc((argc - 1) * sizeof(int));
	exit_if(!s->a.arr || !s->b.arr, s, "Malloc failed!");
	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] == '-' && argv[i][1] == '-')
			*flag = argv[i];
		else
			s->a.arr[s->a.size++] = error_throwing_atoi(argv[i], s);
	}
	s->a.cap = s->a.size;
	s->b.cap = s->a.cap;
	exit_if(s->a.size < 1, s, "You must provide integers to sort!");
	return (s);
}

// flags:
// 0bX00 = adaptive
// 0bX01 = simple
// 0bX10 = medium
// 0bX11 = complex
// 0b1XX = benchmark mode
char	get_numbers(int argc, char **argv, int *numbers)
{
	int		i;
	char	flags;

	exit_if(argc < 2, NULL, "Provide a list of integers to sort!");
	flags = 0;
	i = 1;
	while (i < 3 && i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		flags += 0b100 * (ft_strncmp(argv[i], "--bench", 8) == 0);
		flags |= 0b001 * (ft_strncmp(argv[i], "--simple", 9) == 0);
		flags |= 0b010 * (ft_strncmp(argv[i], "--medium", 9) == 0);
		flags |= 0b011 * (ft_strncmp(argv[i], "--complex", 10) == 0);
		exit_if(i == 2 && (flags < 0b100 || flags > 0b111), NULL, "Flag Err");
		exit_if(!flags && ft_strncmp(argv[i], "--adaptive", 11), 0, "Flag Err");
		i++;
	}
	return (flags);
}

int	main(int argc, char **argv)
{
	char				*flags;
	t_stack_collection	*s;

	if (argc < 2)
		return (ft_putendl_fd("Provide a list of integers to sort!", 1), 1);
	flags = NULL;
	s = init_stacks(argc, argv, &flags);
}
