/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap_ops.c                                   :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 20:35:03 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/19 20:56:13 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_sa(t_data *d)
{
	st_swap(&(d->a));
	return (record(d, SA));
}

int	op_sb(t_data *d)
{
	st_swap(&(d->b));
	return (record(d, SB));
}

int	op_ss(t_data *d)
{
	st_swap(&(d->a));
	st_swap(&(d->b));
	return (record(d, SS));
}

int	op_pa(t_data *d)
{
	st_push_st_to_st(&(d->b), &(d->a));
	return (record(d, PA));
}

int	op_pb(t_data *d)
{
	st_push_st_to_st(&(d->a), &(d->b));
	return (record(d, PB));
}
