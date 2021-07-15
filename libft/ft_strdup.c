/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: locus2 <locus2@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 23:40:20 by locus2            #+#    #+#             */
/*   Updated: 2021/05/07 12:49:17 by locus2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dupstr;
	int		i;

	i = 0;
	dupstr = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dupstr)
		return (NULL);
	while (s[i])
	{
		dupstr[i] = s[i];
		i++;
	}
	dupstr[i] = '\0';
	return (dupstr);
}
