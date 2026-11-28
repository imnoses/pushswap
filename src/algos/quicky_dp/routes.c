/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   routes.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/28 14:28:13 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/28 14:52:37 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "locations.h"
#include "push_swap.h"
#include <stddef.h>

static const t_route	*get_route(t_location from, t_location to)
{
	static const t_route	table[LOCATION_COUNT][LOCATION_COUNT] = {
	{{0, {0}}, {1, {RA}}, {1, {PB}}, {2, {PB, RB}}},
	{{1, {RRA}}, {0, {0}}, {2, {RRA, PB}}, {3, {RRA, PB, RB}}},
	{{1, {PA}}, {2, {PA, RA}}, {0, {0}}, {1, {RB}}},
	{{2, {RRB, PA}}, {3, {RRB, PA, RA}}, {1, {RRB}}, {0, {0}}},
	};

	return (&table[from][to]);
}

size_t	route_len(t_location from, t_location to)
{
	return (get_route(from, to)->len);
}

int	run_route(t_data *d, t_location from, t_location to)
{
	const t_route	*r = get_route(from, to);
	size_t			i;

	i = -1;
	while (++i < r->len)
		if (!get_op_fn(r->ops[i])(d))
			return (0);
	return (1);
}
