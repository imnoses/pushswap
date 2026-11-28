/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   chunks.c                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/28 15:14:17 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/28 15:30:52 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "chunks.h"
#include <stddef.h>

t_part	determine_part(t_chunk chunk, size_t n_low, size_t n_mid, int rank)
{
	rank -= chunk.lo;
	if (rank < (int)n_low)
		return (P_LOW);
	if (rank < (int)(n_low + n_mid))
		return (P_MID);
	return (P_HIGH);
}
