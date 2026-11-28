/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   helpers.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/26 09:54:58 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/28 20:54:19 by paziehen        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "algos.h"
#include "push_swap.h"
#include "stack.h"
#include <stddef.h>

int	is_sorted(t_data *d)
{
	size_t	i;

	if (d->a.size != d->n)
		return (0);
	i = -1;
	while (++i < d->n)
		if (st_at(&d->a, i) != (int)i)
			return (0);
	return (1);
}

int	get_position_of(t_stack s, int value)
{
	int	i;

	i = -1;
	while (++i < (int)s.size)
	{
		if (st_at(&s, i) == value)
			return (i);
	}
	return (-1);
}

int	rotate_a_to(t_data *d, int idx)
{
	if (idx < 0 || idx >= (int)d->a.size)
		return (0);
	if (idx <= (int)d->a.size / 2)
		while (idx--)
			op_ra(d);
	else
		while (idx++ < (int)d->a.size)
			op_rra(d);
	return (1);
}

int	rotate_b_to(t_data *d, int idx)
{
	if (idx < 0 || idx >= (int)d->b.size)
		return (0);
	if (idx <= (int)d->b.size / 2)
		while (idx--)
			op_rb(d);
	else
		while (idx++ < (int)d->b.size)
			op_rrb(d);
	return (1);
}

int	cost_of_rotate_to(t_stack s, int idx)
{
	if (idx < 0 || idx >= (int)s.size)
		return (-1);
	if (idx <= (int)s.size / 2)
		return (idx);
	return (s.size - idx);
}
