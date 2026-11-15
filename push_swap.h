/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/28 14:15:29 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/15 22:08:56 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>

typedef struct s_stack
{
	int		*arr;
	size_t	cap;
	size_t	head;
	size_t	size;
}			t_stack;

typedef enum e_algo
{
	F_ADAPT = 1,
	F_SIMPL = 2,
	F_MEDIU = 3,
	F_COMPL = 4,
}			t_algo;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
	t_algo	algo;
	int		is_bench;
	size_t	n;
}			t_data;

int			ft_isws(char c);

char		status_atoi(const char *nptr, int *result);

int			ft_strcmp(const char *s1, const char *s2);

void		exit_if(int condition, t_data *s);

char		**splitws(char const *s);

t_data		*pars_args(int argc, char **argv);

int			index_array(int *arr, size_t size);

int			st_at(t_stack *s, size_t i);

void		st_push_top(t_stack *s, int v);

int			st_pop_top(t_stack *s);

void		st_push_bot(t_stack *s, int v);

int			st_pop_bot(t_stack *s);

void		free_data(t_data *data);

#endif
