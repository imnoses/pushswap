/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ops_logic.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/11/15 22:31:37 by spuschma         #+#    #+#              */
/*   Updated: 2026/11/15 23:45:46 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

static int	grow_ops(t_data *d)
{
	unsigned char	*new_buf;
	size_t			new_cap;

	if (!d->ops.cap)
		new_cap = 512;
	else
		new_cap = 2 * d->ops.cap;
	new_buf = malloc(new_cap);
	if (!new_buf)
		return (0);
	if (d->ops.buf)
		ft_memcpy(new_buf, d->ops.buf, d->ops.cap);
	d->ops.cap = new_cap;
	free(d->ops.buf);
	d->ops.buf = new_buf;
	return (1);
}

int	record(t_data *d, t_op op)
{
	if (d->ops.cap == d->ops.len && !grow_ops(d))
		return (0);
	d->ops.buf[d->ops.len] = op;
	d->ops.len++;
	return (1);
}

const char	*op_name(t_op op)
{
	if (op == SA)
		return ("sa\n");
	if (op == SB)
		return ("sb\n");
	if (op == SS)
		return ("ss\n");
	if (op == PA)
		return ("pa\n");
	if (op == PB)
		return ("pb\n");
	if (op == RA)
		return ("ra\n");
	if (op == RB)
		return ("rb\n");
	if (op == RR)
		return ("rr\n");
	if (op == RRA)
		return ("rra\n");
	if (op == RRB)
		return ("rrb\n");
	if (op == RRR)
		return ("rrr\n");
	return ("");
}

int	print_ops(t_ops ops)
{
	size_t		i;
	size_t		j;
	char		*buffer;
	const char	*name;

	if (ops.len == 0)
		return (1);
	buffer = malloc(4 * ops.len);
	if (!buffer)
		return (0);
	i = -1;
	j = -1;
	while (++i < ops.len)
	{
		name = op_name(ops.buf[i]);
		while (*name)
			buffer[++j] = *name++;
	}
	write(1, buffer, j + 1);
	free(buffer);
	return (1);
}
