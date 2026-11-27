/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/26 17:53:16 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/27 21:35:38 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */
#include "algos.h"
#include "push_swap.h"
#include <stddef.h>

int	main(int argc, char **argv)
{
	t_data			*d;
	const t_algo	*algo;

	d = pars_args(argc, argv);
	algo = select_algo(d);
	exit_if(!algo || !algo->solve(d) || d->ops.error, d);
	exit_if(!verify(d), d);
	print_ops(d->ops);
	if (d->is_bench)
		print_bench(d, algo);
	free_data(d);
}
