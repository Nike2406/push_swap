/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prrohellllpr<phellhell@student.42fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 18:29:40 by locus2            #+#    #+#             */
/*   Updated: 2021/05/11 15:50:16 by prrohell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nel;

	nel = (t_list *)malloc(sizeof(t_list));
	if (!nel)
		return (NULL);
	nel->content = content;
	nel->next = NULL;
	return (nel);
}
