/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   quicky_dp.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/27 16:41:44 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/28 21:25:35 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

/**
 * 3 way quicksort with DP for determining ideal pivots.
 * Solves any input in O(nlogn) Ops.
 * Provably below 700 Ops for n = 100 and 5500 for n = 500.
 */

#include "chunks.h"
#include "locations.h"
#include "push_swap.h"

int	quicky_dp(t_data *d)
{
	t_chunk	everything;

	everything.loc = L_A_TOP;
	everything.lo = 0;
	everything.size = d->n;
	return (sort_chunk(d, everything));
}

// Equal thirds. % 3 = 1 -> high++, % 3 == 2 -> high++ mid++
t_split	equal_thirds_split(t_chunk c)
{
	t_split	s;

	s.n_low = c.size / 3;
	s.n_mid = c.size / 3;
	if (c.size % 3 == 2)
		s.n_mid++;
	return (s);
}
