/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/26 17:53:16 by spuschma         #+#    #+#              */
/*   Updated: 2026/10/28 14:56:43 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "libft/libft.h"
#include "push_swap.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

t_stack_collection	*init_stacks(int *numbers, int size)
{
	int					i;
	t_stack_collection	*s;

	s = ft_calloc(1, sizeof(t_stack_collection));
	if (!s)
		exit(1);
	s->a.size = size;
	s->a.cap = size;
	s->b.cap = size;
	s->a.arr = numbers;
	s->b.arr = malloc(size * sizeof(int));
	exit_if(!s->a.arr || !s->b.arr, s, "Malloc failed!");
	exit_if(s->a.size < 1, s, "You must provide integers to sort!");
	return (s);
}

size_t	count_dooku(int n, char **list)
{
	size_t	result;
	int		arg;
	size_t	i;

	result = 0;
	arg = -1;
	while (++arg < n)
	{
		i = -1;
		while (list[arg][++i])
		{
			if (ft_isdigit(list[arg][i]) && (!list[arg][i + 1]
					|| ft_isws(list[arg][i + 1])))
				result++;
		}
	}
	return (result);
}

// returns the offset to the first argument after the flags
int	get_flags(int argc, char **argv, char *flags)
{
	int	i;

	*flags = 0;
	i = 1;
	while (i < 3 && i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		*flags ^= F_ADAPT * (ft_strcmp(argv[i], "--adaptive") == 0);
		*flags ^= F_SIMPL * (ft_strcmp(argv[i], "--simple") == 0);
		*flags ^= F_MEDIU * (ft_strcmp(argv[i], "--medium") == 0);
		*flags ^= F_COMPL * (ft_strcmp(argv[i], "--complex") == 0);
		*flags ^= F_BENCH * (ft_strcmp(argv[i], "--bench") == 0);
		if (!*flags || (i > 1 && (!(*flags & (*flags - 1))
					|| !(*flags & F_BENCH))))
			exit((ft_putendl_fd("Flag Error!", 2), 1));
		i++;
	}
	return (i);
}

char	pars_args(int argc, char **argv, int **numbers, int *size)
{
	int		i;
	int		j;
	int		k;
	char	**number_strs;
	char	flags;

	i = get_flags(argc, argv, &flags);
	numbers = malloc(count_dooku(argc - i, argv + i) * sizeof(int));
	j = 0;
	while (i < argc)
	{
		number_strs = splitws(argv[i++]);
		k = -1;
		while (number_strs[++k])
		{
			numbers[0][j++] = error_throwing_atoi(number_strs[k],
					"One of the numbers is malformed!");
			free(number_strs[k]);
		}
		free(number_strs);
	}
	*size = j;
	return (flags);
}

int	main(int argc, char **argv)
{
	char				flags;
	t_stack_collection	*s;
	int					*numbers;
	int					size;

	if (argc < 2)
		return (ft_putendl_fd("Provide a list of integers to sort!", 1), 1);
	flags = pars_args(argc, argv, &numbers, &size);
	s = init_stacks(numbers, size);
}
