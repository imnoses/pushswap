/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/28 14:15:29 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/27 17:32:04 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"
# include <stddef.h>

typedef enum e_strategy
{
	F_UNSELECTED = 0,
	F_ADAPT,
	F_SIMPL,
	F_MEDIU,
	F_COMPL,
}					t_strategy;

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR,
	OP_COUNT
}					t_op;

typedef struct s_ops
{
	unsigned char	*buf;
	size_t			len;
	size_t			cap;
	int				error;
}					t_ops;

typedef struct s_data
{
	t_stack			a;
	t_stack			b;
	t_strategy		strategy;
	int				is_bench;
	size_t			n;
	t_ops			ops;
	unsigned int	disorder;
	int				*initial_arr;
}					t_data;

typedef int			(*t_op_fn)(t_data *d);

int					ft_isws(char c);

char				status_atoi(const char *nptr, int *result);

int					ft_strcmp(const char *s1, const char *s2);

void				exit_if(int condition, t_data *s);

char				**splitws(char const *s);

t_data				*pars_args(int argc, char **argv);

int					index_array(int *arr, size_t size);

int					record(t_data *d, t_op op);

int					print_ops(t_ops ops);

int					op_sa(t_data *d);

int					op_sb(t_data *d);

int					op_ss(t_data *d);

int					op_pa(t_data *d);

int					op_pb(t_data *d);

int					op_ra(t_data *d);

int					op_rb(t_data *d);

int					op_rr(t_data *d);

int					op_rrr(t_data *d);

int					op_rrb(t_data *d);

int					op_rra(t_data *d);

t_op_fn				get_op_fn(t_op op);

void				free_data(t_data *data);

t_data				*copy_data(t_data *og);

unsigned int		compute_disorder(int *arr, size_t size);

#endif
