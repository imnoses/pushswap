/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parsing.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/28 17:06:36 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/14 22:32:47 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static t_data	*init_stacks(int *numbers, int n, t_flags flags)
{
	t_data	*s;

	s = ft_calloc(1, sizeof(t_data));
	if (!s)
		exit((ft_putendl_fd("Error", 2), free(numbers), 1));
	s->n = n;
	s->flags = flags;
	s->a.size = n;
	s->a.cap = n;
	s->b.cap = n;
	s->a.arr = numbers;
	s->b.arr = malloc(n * sizeof(int));
	exit_if(!s->a.arr || !s->b.arr || s->a.size < 1, s);
	return (s);
}

static size_t	count_dooku(int n, char **list)
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
			if (!ft_isws(list[arg][i]) && (!list[arg][i + 1]
					|| ft_isws(list[arg][i + 1])))
				result++;
		}
	}
	return (result);
}

// returns the offset to the first argument after the flags
static int	get_flags(int argc, char **argv, t_flags *flags)
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
			exit((ft_putendl_fd("Error", 2), 1));
		i++;
	}
	return (i);
}

static int	fill_array(int argc, char **argv, int *nums)
{
	int		err;
	int		i;
	size_t	j;
	size_t	k;
	char	**num_strs;

	err = 0;
	i = 0;
	j = 0;
	while (i < argc)
	{
		num_strs = splitws(argv[i++]);
		if (!num_strs)
			return (-1);
		k = -1;
		while (num_strs[++k])
		{
			err |= !status_atoi(num_strs[k], nums + j++);
			free(num_strs[k]);
		}
		free(num_strs);
	}
	if (err)
		return (-1);
	return (j);
}

t_data	*pars_args(int argc, char **argv)
{
	int		offset;
	int		*nums;
	size_t	size_upper_bound;
	t_flags	flags;
	ssize_t	actual_size;

	offset = get_flags(argc, argv, &flags);
	size_upper_bound = count_dooku(argc - offset, argv + offset);
	nums = malloc(size_upper_bound * sizeof(int));
	if (!nums)
		exit((ft_putendl_fd("Error", 2), 1));
	actual_size = fill_array(argc - offset, argv + offset, nums);
	if (actual_size == 0)
		exit((free(nums), 0));
	if (!index_array(nums, actual_size))
		exit((ft_putendl_fd("Error", 2), free(nums), 1));
	return (init_stacks(nums, actual_size, flags));
}
