/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 14:20:43 by locus2            #+#    #+#             */
/*   Updated: 2021/05/11 01:35:88 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	while (dst[i] && i < dstsize)
		i++;
	while (src[k] && (i + k + 1) < dstsize)
	{
		dst[i + k] = src[k];
		k++;
	}
	if (i < dstsize)
		dst[i + k] = '\0';
	return (i + ft_strlen(src));
}
