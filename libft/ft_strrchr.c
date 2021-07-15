/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locus2 <locus2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 18:10:45 by locus2            #+#    #+#             */
/*   Updated: 2021/05/07 12:46:08 by locus2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	temp;

	temp = ft_strlen(s);
	while (temp > 0 && s[temp] != (char)c)
		temp--;
	if (s[temp] == (char)c)
		return ((char *)s + temp);
	return (NULL);
}
