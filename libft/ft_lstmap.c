/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/09 13:10:39 by locus2            #+#    #+#             */
/*   Updated: 2021/05/10 21:37:42 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nelm;
	t_list	*nlst;

	if (!f || !lst)
		return (NULL);
	nlst = NULL;
	while (lst)
	{
		nelm = ft_lstnew(f(lst->content));
		if (!nelm)
		{
			ft_lstclear(&nlst, del);
			return (NULL);
		}
		ft_lstadd_back(&nlst, nelm);
		lst = lst->next;
	}
	return (nlst);
}
