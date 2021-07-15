/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locus2 <locus2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 15:00:03 by locus2            #+#    #+#             */
/*   Updated: 2021/05/07 12:44:55 by locus2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*ptr1;
	char	*ptr2;

	ptr1 = (char *)dest;
	ptr2 = (char *)src;
	if (!n || dest == src)
		return (dest);
	else if (ptr2 < ptr1)
		while (n--)
			ptr1[n] = ptr2[n];
	else
		while (n-- > 0)
			*ptr1++ = *ptr2++;
	return (dest);
}
