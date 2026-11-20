/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   stack_internal.h                                  :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/20 14:58:41 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/20 14:58:43 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_INTERNAL_H
# define STACK_INTERNAL_H

# include "stack.h"

void	st_push_top(t_stack *s, int v);

int		st_pop_top(t_stack *s);

void	st_push_bot(t_stack *s, int v);

int		st_pop_bot(t_stack *s);

#endif
