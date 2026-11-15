/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstclear.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/17 13:29:05 by spuschma         #+#    #+#              */
/*   Updated: 2026/09/18 09:56:53 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	recursive_clear(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	(*del)(lst->content);
	recursive_clear(lst->next, del);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (lst)
	{
		recursive_clear(*lst, del);
		*lst = NULL;
	}
}
