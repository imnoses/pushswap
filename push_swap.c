/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/26 17:53:16 by spuschma         #+#    #+#              */
/*   Updated: 2026/10/27 16:19:20 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include <stddef.h>
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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = -1;
	while (s1[++i] && s1[i] == s2[i])
		;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

typedef enum e_flag
{
	F_ADAPT = 0b00001,
	F_SIMPL = 0b00010,
	F_MEDIU = 0b00100,
	F_COMPL = 0b01000,
	F_BENCH = 0b10000,
}					t_flag;

size_t	count_numbers(int count, char **l)
{
	int		i;
	size_t	r;

	r = 0;
	while (count-- && l++)
	{
		i = -1;
		while (*l[i])
			r += (*l[i] >= '0' && *l[i] <= '9' && ((*l[++i] >= '\t'
							&& *l[i] <= '\f') || *l[i] == ' ' || !*l[i]));
	}
	return (r);
}

char	get_numbers(int argc, char **argv, int *numbers)
{
	int		i;
	char	flags;
	int		n;

	flags = 0;
	i = 1;
	while (i < 3 && i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		flags ^= F_ADAPT * (ft_strcmp(argv[i], "--adaptive") == 0);
		flags ^= F_SIMPL * (ft_strcmp(argv[i], "--simple") == 0);
		flags ^= F_MEDIU * (ft_strcmp(argv[i], "--medium") == 0);
		flags ^= F_COMPL * (ft_strcmp(argv[i], "--complex") == 0);
		flags ^= F_BENCH * (ft_strcmp(argv[i], "--bench") == 0);
		if (!flags || (i > 1 && (!(flags & (flags - 1)) || !(flags & F_BENCH))))
			exit((ft_putendl_fd("Flag Error!", 2), 1));
		i++;
	}
	n = count_numbers(argc - i, argv + i);
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
