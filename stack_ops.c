/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   stack_ops.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 23:50:39 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/19 20:56:09 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	st_swap(t_stack *s)
{
	int	v1;
	int	v2;

	if (s->size < 2)
		return ;
	v1 = st_pop_top(s);
	v2 = st_pop_top(s);
	st_push_top(s, v1);
	st_push_top(s, v2);
}

void	st_rotate(t_stack *s)
{
	if (s->size < 2)
		return ;
	st_push_bot(s, st_pop_top(s));
}

void	st_reverse_rotate(t_stack *s)
{
	if (s->size < 2)
		return ;
	st_push_top(s, st_pop_bot(s));
}

void	st_push_st_to_st(t_stack *src, t_stack *dest)
{
	if (src->size < 1)
		return ;
	st_push_top(dest, st_pop_top(src));
}
