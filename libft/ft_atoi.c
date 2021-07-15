/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 21:16:55 by locus2            #+#    #+#             */
/*   Updated: 2021/05/10 23:33:06 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_limits(long long total, char const s, int sign)
{
	long long	min;
	long long	max;

	max = (total * 10 + (s - '0')) * sign;
	if (max > 2147483647)
		return (-1);
	min = (total * 10 + (s - '0')) * sign;
	if (min < -2147483648)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				min;
	long long		total;
	int				lim;

	i = 0;
	min = 1;
	total = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			min = -min;
	while (str[i] >= '0' && str[i] <= '9')
	{
		lim = ft_limits(total, str[i], min);
		if (lim < 1)
			return (lim);
		total = (total * 10) + (str[i] - 48);
		i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (total * min);
	}
	return (0);
}
