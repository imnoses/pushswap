/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   parsing.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/28 17:06:36 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/15 21:44:06 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stddef.h>
#include <stdlib.h>

static t_data	*init_stacks(int *numbers, int n, t_algo algo, int is_bench)
{
	t_data	*s;

	s = ft_calloc(1, sizeof(t_data));
	if (!s)
		exit((ft_putendl_fd("Error", 2), free(numbers), 1));
	s->n = n;
	s->algo = algo;
	s->is_bench = is_bench;
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

static int	check_flags(int argc, char **argv, t_algo *algo, int *is_bench)
{
	int	i;

	*algo = 0;
	*is_bench = 0;
	i = 1;
	while (i < 3 && i < argc && argv[i][0] == '-' && argv[i][1] == '-')
	{
		if (!*is_bench && ft_strcmp(argv[i], "--bench") == 0)
			*is_bench = 1;
		else if (!*algo)
		{
			*algo += (ft_strcmp(argv[i], "--adaptive") == 0) * F_ADAPT;
			*algo += (ft_strcmp(argv[i], "--simple") == 0) * F_SIMPL;
			*algo += (ft_strcmp(argv[i], "--medium") == 0) * F_MEDIU;
			*algo += (ft_strcmp(argv[i], "--complex") == 0) * F_COMPL;
			if (!*algo)
				exit((ft_putendl_fd("Error", 2), 1));
		}
		else
			exit((ft_putendl_fd("Error", 2), 1));
		i++;
	}
	if (!*algo)
		*algo = F_ADAPT;
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
	int		offset;
	int		*nums;
	ssize_t	size;
	t_algo	algo;
	int		is_bench;

	offset = check_flags(argc, argv, &algo, &is_bench);
	size = count_dooku(argc - offset, argv + offset);
	nums = malloc(size * sizeof(int));
	if (!nums && size > 0)
		exit((ft_putendl_fd("Error", 2), 1));
	size = fill_array(argc - offset, argv + offset, nums);
	if (size == 0)
		exit((free(nums), 0));
	if (size < 0 || !index_array(nums, size))
		exit((ft_putendl_fd("Error", 2), free(nums), 1));
	return (init_stacks(nums, size, algo, is_bench));
}
