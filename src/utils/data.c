/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spuschma <spuschma@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/27 21:28:18 by spuschma          #+#    #+#             */
/*   Updated: 2026/11/27 21:36:30 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include <stddef.h>
#include <stdlib.h>

// Resets d in place to its starting state: ranks in a, empty b, no ops.
void	rewind_data(t_data *d)
{
	d->a.size = d->n;
	d->b.size = 0;
	d->a.head = 0;
	d->b.head = 0;
	ft_memcpy(d->a.arr, d->initial_arr, d->n * sizeof(int));
	d->ops.error = 0;
	d->ops.len = 0;
}

// Replays the ops recorded in d on a fresh copy of the starting state.
// Returns 1 if that sorts it, 0 if not (or if the copy could not be made).
int	verify(t_data *d)
{
	t_data	*clone;
	size_t	i;
	int		ret;

	clone = copy_data(d);
	if (!clone)
		return (0);
	rewind_data(clone);
	i = -1;
	while (++i < d->ops.len)
		get_op_fn(d->ops.buf[i])(clone);
	ret = is_sorted(clone) && !clone->ops.error;
	free_data(clone);
	return (ret);
}

// Ops wont be copied
t_data	*copy_data(t_data *og)
{
	t_data	*d;

	d = ft_calloc(1, sizeof(t_data));
	if (!d)
		return (NULL);
	d->n = og->n;
	d->strategy = og->strategy;
	d->is_bench = og->is_bench;
	d->a.size = og->a.size;
	d->b.size = og->b.size;
	d->a.cap = og->a.cap;
	d->b.cap = og->b.cap;
	d->a.head = og->a.head;
	d->b.head = og->b.head;
	d->disorder = og->disorder;
	d->initial_arr = malloc(d->n * sizeof(int));
	d->a.arr = malloc(d->a.cap * sizeof(int));
	d->b.arr = malloc(d->b.cap * sizeof(int));
	if (!d->initial_arr || !d->a.arr || !d->b.arr)
		return (free_data(d), NULL);
	ft_memcpy(d->initial_arr, og->initial_arr, og->n * sizeof(int));
	ft_memcpy(d->a.arr, og->a.arr, og->a.cap * sizeof(int));
	ft_memcpy(d->b.arr, og->b.arr, og->b.cap * sizeof(int));
	return (d);
}
