/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstmap.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: spuschma <spuschma@student.42vienna.com>  #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/17 13:54:40 by spuschma         #+#    #+#              */
/*   Updated: 2026/09/18 09:54:21 by spuschma        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*og_current;
	t_list	*cp;
	t_list	*cp_current;
	void	*new_content;

	if (!lst || !f || !del)
		return (NULL);
	og_current = lst;
	new_content = (*f)(og_current->content);
	cp = ft_lstnew(new_content);
	if (!cp)
		return ((*del)(new_content), NULL);
	cp_current = cp;
	og_current = og_current->next;
	while (og_current)
	{
		new_content = (*f)(og_current->content);
		cp_current->next = ft_lstnew(new_content);
		if (!cp_current->next)
			return (ft_lstclear(&cp, del), (*del)(new_content), NULL);
		cp_current = cp_current->next;
		og_current = og_current->next;
	}
	return (cp);
}
