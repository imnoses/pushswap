/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   selector.c                                        :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/27 15:51:41 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/28 19:42:44 by paziehen        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "algos.h"
#include "greedy_insertion.h"
#include "push_swap.h"

// PLACEHOLDERS!
int				quicky_dp(t_data *d);
int				medium(t_data *d);
// int				greedy_insertion(t_data *d);
//^^^is defined in greedy_insertion. Prototype can be deleted.

const t_algo	*select_algo(t_data *d)
{
	static const t_algo table[] = {
		{"quicky_dp", C_N_LOG_N, quicky_dp},
		{"medium", C_SQRT_N, medium},
		{"simple", C_QUADRATIC, greedy_insertion},
	};
	if (d->strategy == F_UNSELECTED)
		return (NULL);
	if (d->strategy == F_COMPL)
		return (&table[0]);
	if (d->strategy == F_MEDIU)
		return (&table[1]);
	if (d->strategy == F_SIMPL)
		return (&table[2]);
	if (d->strategy == F_ADAPT)
	{
		if (d->disorder < 2000)
			return (&table[2]);
		if (d->disorder < 5000)
			return (&table[1]);
		return (&table[0]);
	}
	return (&table[0]);
}
