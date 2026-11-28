/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   locations.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/28 13:56:13 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/28 14:12:26 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "locations.h"
#include "push_swap.h"
#include "stack.h"
#include <stddef.h>

/**
 * Returns the rank of the given index of the given location.
 * Does not check if i > size of the location.
 * Only returns -1 for invalid lacation enum values.
 */
int	loc_at(t_data *d, t_location location, size_t i)
{
	if (location == L_A_TOP)
		return (st_at(&d->a, i));
	if (location == L_A_BOT)
		return (st_at(&d->a, (d->a.size - 1) - i));
	if (location == L_B_TOP)
		return (st_at(&d->b, i));
	if (location == L_B_BOT)
		return (st_at(&d->b, (d->b.size - 1) - i));
	return (-1);
}
