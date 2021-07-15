/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:14:53 by locus2            #+#    #+#             */
/*   Updated: 2021/06/01 23:58:06 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nmblen(long long int n)
{
	int	ln;

	ln = 0;
	if (n < 0)
	{
		n = -n;
		ln++;
	}
	while (n > 0)
	{
		n /= 10;
		ln++;
	}
	return (ln);
}

char	*ft_itoa(long long int n)
{
	char	*itnb;
	int		ln;

	if (n < 0)
		n = n * -1;
	ln = ft_nmblen(n);
	if (n == 0)
		return (ft_strdup("0"));
	itnb = (char *)malloc(sizeof(char) * ln + 1);
	if (!itnb)
		return (NULL);
	itnb[ln--] = '\0';
	while (n > 0)
	{
		itnb[ln] = n % 10 + 48;
		n /= 10;
		ln--;
	}
	return (itnb);
}
