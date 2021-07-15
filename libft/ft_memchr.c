/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locus2 <locus2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 12:00:40 by locus2            #+#    #+#             */
/*   Updated: 2021/05/07 12:44:45 by locus2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	sym;

	tmp = (unsigned char *)s;
	i = 0;
	sym = (unsigned char)c;
	while (i < n)
	{
		if (tmp[i] == sym)
			return (&tmp[i]);
		i++;
	}
	return (NULL);
}
