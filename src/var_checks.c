/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:29:26 by prochell          #+#    #+#             */
/*   Updated: 2021/07/29 12:34:33 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_err(int	code)
{
	if (code == 1)
		ft_putstr("Error\n");
	else
		ft_putstr("Unexpected error.\n");
	exit(code);
}

void	check_isnum(char *argv)
{
	int	j;
	int	f;

	j = 0;
	f = 0;
	while (argv[j])
	{
		if (!(argv[j] >= '0' && argv[j] <= '9'))
		{
			if (argv[j] == '-' && !f && !j)
			{
				f++;
				if (!(argv[j + 1] >= '0' && argv[j + 1] <= '9'))
					ft_err(1);
			}
			else
				ft_err(1);
		}
		j++;
	}
}

void	check_sorted(t_stack *lst)
{
	while (lst->next)
	{
		if (lst->value < lst->next->value)
			lst = lst->next;
		else
			return ;
	}
	exit(0);
}

void	check_repeat(t_ps_struct *s_psw)
{
	int	i;

	i = 0;
	while (i < s_psw->arr_len - 1)
	{
		if (s_psw->int_arr[i] == s_psw->int_arr[i + 1])
			ft_err(1);
		i++;
	}
}
