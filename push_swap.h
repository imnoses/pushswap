/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   push_swap.h                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/28 14:15:29 by spuschma         #+#    #+#              */
/*   Updated: 2026/10/28 14:56:38 by spuschma        ###   ########.fr        */
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

typedef struct s_stack_collection
{
	t_stack	a;
	t_stack	b;
}			t_stack_collection;

typedef enum e_flag
{
	F_ADAPT = 0b00001,
	F_SIMPL = 0b00010,
	F_MEDIU = 0b00100,
	F_COMPL = 0b01000,
	F_BENCH = 0b10000,
}			t_flag;

int			ft_isws(char c);

int			error_throwing_atoi(const char *nptr, char *error_message);

int			ft_strcmp(const char *s1, const char *s2);

void		exit_if(int condition, t_stack_collection *s, char *message);

char		**splitws(char const *s);

#endif
