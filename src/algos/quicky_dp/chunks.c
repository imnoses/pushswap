/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   chunks.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/28 15:14:17 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/28 16:27:54 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "chunks.h"
#include "locations.h"
#include <stddef.h>

t_part	determine_part(t_chunk chunk, t_split split, int rank)
{
	rank -= chunk.lo;
	if (rank < (int)split.n_low)
		return (P_LOW);
	if (rank < (int)(split.n_low + split.n_mid))
		return (P_MID);
	return (P_HIGH);
}

static t_location	dest_of(t_location from, t_part part)
{
	static const t_location	table[LOCATION_COUNT][3] = {
	{L_B_BOT, L_A_BOT, L_B_TOP},
	{L_B_BOT, L_B_TOP, L_A_TOP},
	{L_A_BOT, L_B_BOT, L_A_TOP},
	{L_A_BOT, L_B_TOP, L_A_TOP},
	};

	return (table[from][part]);
}

static void	fill_chunks(t_chunk c, t_split s, t_chunk out[3])
{
	out[P_LOW].loc = dest_of(c.loc, P_LOW);
	out[P_LOW].lo = c.lo;
	out[P_LOW].size = s.n_low;
	out[P_MID].loc = dest_of(c.loc, P_MID);
	out[P_MID].lo = c.lo + s.n_low;
	out[P_MID].size = s.n_mid;
	out[P_HIGH].loc = dest_of(c.loc, P_HIGH);
	out[P_HIGH].lo = c.lo + s.n_low + s.n_mid;
	out[P_HIGH].size = c.size - (s.n_low + s.n_mid);
}

int	split_chunk(t_data *d, t_chunk c, t_split s, t_chunk out[3])
{
	size_t	i;
	int		value;
	t_part	part;

	fill_chunks(c, s, out);
	i = -1;
	while (++i < c.size)
	{
		value = loc_at(d, c.loc, 0);
		part = determine_part(c, s, value);
		if (!run_route(d, c.loc, out[part].loc))
			return (0);
	}
	return (1);
}
