/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap_rotate_ops.c                            :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/19 20:43:56 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/19 20:55:03 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	op_ra(t_data *d)
{
	st_rotate(&(d->a));
	return (record(d, RA));
}

int	op_rb(t_data *d)
{
	st_rotate(&(d->b));
	return (record(d, RB));
}

int	op_rr(t_data *d)
{
	st_rotate(&(d->a));
	st_rotate(&(d->b));
	return (record(d, RR));
}
