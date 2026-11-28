/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   locations.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/28 13:57:47 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/28 14:10:32 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOCATIONS_H
# define LOCATIONS_H

# include "push_swap.h"
# include <stddef.h>

// ORDER OF THE LOCATIONS MUST STAY FIXED!
typedef enum e_location
{
	L_A_TOP,
	L_A_BOT,
	L_B_TOP,
	L_B_BOT,
	LOCATION_COUNT
}	t_location;

int	loc_at(t_data *d, t_location location, size_t i);

#endif
