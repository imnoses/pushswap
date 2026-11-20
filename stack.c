/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   stack.c                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 21:53:22 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/15 22:08:08 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "stack_internal.h"
#include <stddef.h>

int	st_at(t_stack *s, size_t i)
{
	return (s->arr[(s->head + i) % s->cap]);
}

void	st_push_top(t_stack *s, int v)
{
	s->head = (s->head + s->cap - 1) % s->cap;
	s->arr[s->head] = v;
	s->size++;
}

int	st_pop_top(t_stack *s)
{
	int	v;

	v = s->arr[s->head];
	s->head = (s->head + 1) % s->cap;
	s->size--;
	return (v);
}

void	st_push_bot(t_stack *s, int v)
{
	s->arr[(s->head + s->size) % s->cap] = v;
	s->size++;
}

int	st_pop_bot(t_stack *s)
{
	s->size--;
	return (s->arr[(s->head + s->size) % s->cap]);
}
