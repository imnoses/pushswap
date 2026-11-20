/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   stack.h                                           :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/20 14:58:53 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/20 14:58:55 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stddef.h>

typedef struct s_stack
{
	int		*arr;
	size_t	cap;
	size_t	head;
	size_t	size;
}			t_stack;

int			st_at(t_stack *s, size_t i);

void		st_swap(t_stack *s);

void		st_rotate(t_stack *s);

void		st_reverse_rotate(t_stack *s);

void		st_push_st_to_st(t_stack *src, t_stack *dest);

#endif
