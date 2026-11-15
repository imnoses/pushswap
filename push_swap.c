/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/26 17:53:16 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/14 22:04:59 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stddef.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	t_data	*d;

	d = pars_args(argc, argv);
	free(d);
}
