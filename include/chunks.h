/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   chunks.h                                          :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/28 15:12:24 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/28 21:22:44 by spuschma        ###   ########.fr        */
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

typedef struct s_split
{
	size_t		n_low;
	size_t		n_mid;
}				t_split;

t_part			determine_part(t_chunk chunk, t_split split, int rank);

int				split_chunk(t_data *d, t_chunk c, t_split s, t_chunk out[3]);

int				sort_chunk(t_data *d, t_chunk c);

#endif
