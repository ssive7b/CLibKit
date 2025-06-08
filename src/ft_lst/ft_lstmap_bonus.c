/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sstoev <sstoev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 17:24:11 by sstoev            #+#    #+#             */
/*   Updated: 2024/09/30 15:24:47 by sstoev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_error_lstclear(t_list **new_list, void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*current_node;
	void	*my_content;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		my_content = f(lst->content);
		if (!my_content)
			ft_error_lstclear(&new_list, del);
		current_node = ft_lstnew(my_content);
		if (!current_node)
		{
			del(my_content);
			ft_error_lstclear(&new_list, del);
		}
		ft_lstadd_back(&new_list, current_node);
		lst = lst->next;
	}
	return (new_list);
}

static void	*ft_error_lstclear(t_list **new_list, void (*del)(void *))
{
	ft_lstclear(new_list, del);
	return (NULL);
}
