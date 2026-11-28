/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   chunks.h                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/28 15:12:24 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/28 15:32:21 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHUNKS_H
# define CHUNKS_H

# include "locations.h"
# include <stddef.h>

typedef struct s_chunk
{
	t_location	loc;
	int			lo;
	size_t		size;
}				t_chunk;

typedef enum e_part
{
	P_LOW,
	P_MID,
	P_HIGH,
}				t_part;

t_part			determine_part(t_chunk chunk, size_t n_low, size_t n_mid,
					int rank);

#endif
