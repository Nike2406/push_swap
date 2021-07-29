/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:29:13 by prochell          #+#    #+#             */
/*   Updated: 2021/07/29 12:30:03 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	init_move(t_move *moves)
{
	moves->l_size = 0;
	moves->pos = 0;
	moves->ra = 0;
	moves->rb = 0;
	moves->rra = 0;
	moves->rrb = 0;
}

void	get_length(t_ps_struct *s_psw)
{
	int		i;
	int		j;
	char	**tmp;

	i = 1;
	while (s_psw->argv[i])
	{
		tmp = ft_split(s_psw->argv[i], ' ');
		j = 0;
		while (tmp[j])
		{
			s_psw->arr_len++;
			j++;
		}
		i++;
		j = 0;
		while (tmp[j])
		{
			free(tmp[j]);
			j++;
		}
		free(tmp);
	}
}

int	ft_limits_ps(long long total, char const s, int sign)
{
	long long	min;
	long long	max;

	max = (total * 10 + (s - '0')) * sign;
	if (max > 2147483647)
		return (0);
	min = (total * 10 + (s - '0')) * sign;
	if (min < -2147483648)
		return (-1);
	return (1);
}

int	ft_atoi_ps(const char *str)
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
		lim = ft_limits_ps(total, str[i], min);
		if (lim < 1)
			ft_err(1);
		total = (total * 10) + (str[i] - 48);
		i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (total * min);
	}
	return (0);
}
