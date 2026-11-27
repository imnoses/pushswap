/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ops_table.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/27 17:12:53 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/27 17:17:39 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op_fn	get_op_fn(t_op op)
{
	static const t_op_fn	table[OP_COUNT] = {
		op_sa, op_sb, op_ss, op_pa, op_pb, op_ra, op_rb, op_rr, op_rra, op_rrb,
		op_rrr
	};

	return (table[op]);
}
