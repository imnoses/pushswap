/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parsing.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/28 17:06:36 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/27 17:38:22 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stddef.h>
#include <stdlib.h>

static t_data	*init_stacks(int *numbers, int n, t_strategy strategy,
		int is_bench)
{
	t_data	*d;

	d = ft_calloc(1, sizeof(t_data));
	if (!d)
		exit((ft_putendl_fd("Error", 2), free(numbers), 1));
	d->initial_arr = numbers;
	d->n = n;
	d->strategy = strategy;
	d->is_bench = is_bench;
	d->a.size = n;
	d->a.cap = n;
	d->b.cap = n;
	d->disorder = compute_disorder(numbers, n);
	d->a.arr = malloc(n * sizeof(int));
	d->b.arr = malloc(n * sizeof(int));
	exit_if(!d->a.arr || !d->b.arr || d->a.size < 1, d);
	ft_memcpy(d->a.arr, numbers, n * sizeof(int));
	return (d);
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

static int	check_flags(int argc, char **argv, t_strategy *strategy,
		int *is_bench)
{
	int	i;

	*strategy = 0;
	*is_bench = 0;
	i = 1;
	while (i < 3 && i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!*is_bench && ft_strcmp(argv[i], "--bench") == 0)
			*is_bench = 1;
		else if (!*strategy)
		{
			*strategy += (ft_strcmp(argv[i], "--adaptive") == 0) * F_ADAPT;
			*strategy += (ft_strcmp(argv[i], "--simple") == 0) * F_SIMPL;
			*strategy += (ft_strcmp(argv[i], "--medium") == 0) * F_MEDIU;
			*strategy += (ft_strcmp(argv[i], "--complex") == 0) * F_COMPL;
			if (!*strategy)
				exit((ft_putendl_fd("Error", 2), 1));
		}
		else
			exit((ft_putendl_fd("Error", 2), 1));
		i++;
	}
	if (!*strategy)
		*strategy = F_ADAPT;
	return (i);
}

static ssize_t	fill_array(int argc, char **argv, int *nums)
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
	int			offset;
	int			*nums;
	ssize_t		size;
	t_strategy	strategy;
	int			is_bench;

	offset = check_flags(argc, argv, &strategy, &is_bench);
	size = count_dooku(argc - offset, argv + offset);
	nums = malloc(size * sizeof(int));
	if (!nums && size > 0)
		exit((ft_putendl_fd("Error", 2), 1));
	size = fill_array(argc - offset, argv + offset, nums);
	if (size == 0)
		exit((free(nums), 0));
	if (size < 0 || !index_array(nums, size))
		exit((ft_putendl_fd("Error", 2), free(nums), 1));
	return (init_stacks(nums, size, strategy, is_bench));
}
