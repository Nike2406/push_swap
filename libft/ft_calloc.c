/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locus2 <locus2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 23:30:06 by locus2            #+#    #+#             */
/*   Updated: 2021/05/07 12:39:48 by locus2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tmp;

	tmp = malloc(size * nmemb);
	if (!tmp)
		return (NULL);
	ft_memset(tmp, 0, size * nmemb);
	return (tmp);
}
