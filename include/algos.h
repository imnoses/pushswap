/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   algos.h                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/27 15:18:35 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/28 21:49:08 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGOS_H
# define ALGOS_H
# include "push_swap.h"

/*	Algorithms for sorting t_data.
 *	Before the function runs, d holds the unsorted stack a along with an empty
 *	stack b. The values in a are ranks, not the actual values.
 *
 *	After d holds the sorted stack a, an empty stack b and the ops recorded
 *	in d->ops.
 *	The function is not allowed to print out anything, or exit the program.
 *	On errors the return value is 0, on success 1.
 */
typedef int			(*t_algo_fn)(t_data *d);

typedef enum e_complexity
{
	C_QUADRATIC,
	C_SQRT_N,
	C_N_LOG_N,
}					t_complexity;

typedef struct s_algo
{
	const char		*name;
	t_complexity	complexity;
	t_algo_fn		solve;
}					t_algo;

const t_algo		*select_algo(t_data *d);

void				print_bench(t_data *d, const t_algo *algo);

int					quicky_dp(t_data *d);

#endif
