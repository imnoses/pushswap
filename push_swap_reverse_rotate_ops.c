/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap_reverse_rotate_ops.c                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 20:47:06 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/19 20:50:01 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_rra(t_data *d)
{
	st_reverse_rotate(&(d->a));
	return (record(d, RRA));
}

int	op_rrb(t_data *d)
{
	st_reverse_rotate(&(d->b));
	return (record(d, RRB));
}

int	op_rrr(t_data *d)
{
	st_reverse_rotate(&(d->a));
	st_reverse_rotate(&(d->b));
	return (record(d, RRR));
}
