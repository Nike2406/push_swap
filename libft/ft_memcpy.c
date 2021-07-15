/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locus2 <locus2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 00:01:15 by locus2            #+#    #+#             */
/*   Updated: 2021/05/07 12:44:51 by locus2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char *)dest;
	ptr2 = (char *)src;
	if (!n || dest == src)
		return (dest);
	while (n > 0)
	{
		*ptr1++ = *ptr2++;
		n--;
	}
	return (dest);
}
