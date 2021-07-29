/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:29:04 by prochell          #+#    #+#             */
/*   Updated: 2021/07/29 12:29:06 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_elem(t_move *moves, t_stack **l_a, t_stack **l_b)
{
	while (moves->ra || moves->rra || moves->rb || moves->rrb)
	{
		if (moves->ra && moves->rb)
		{
			rr(l_a, l_b);
			moves->ra--;
			moves->rb--;
			ft_putstr("rr\n");
		}
		else if (moves->rra && moves->rrb)
		{
			rrr(l_a, l_b);
			moves->rra--;
			moves->rrb--;
			ft_putstr("rrr\n");
		}
		else
			sort_elem_add(moves, l_a, l_b);
	}
	if (l_b)
	{
		pab(l_b, l_a);
		ft_putstr("pa\n");
	}
}

void	sort_elem_add(t_move *moves, t_stack **l_a, t_stack **l_b)
{
	if (moves->ra > 0)
	{
		rab(l_a);
		moves->ra--;
		ft_putstr("ra\n");
	}
	else if (moves->rb > 0)
	{
		rab(l_b);
		moves->rb--;
		ft_putstr("rb\n");
	}
	else if (moves->rra > 0)
	{
		rrab(l_a);
		moves->rra--;
		ft_putstr("rra\n");
	}
	else if (moves->rrb > 0)
	{
		rrab(l_b);
		moves->rrb--;
		ft_putstr("rrb\n");
	}
}

void	last_sort(t_move *moves, t_stack **l_a)
{
	init_move(moves);
	moves->l_size = ft_lstsize_ps(*l_a);
	moves->pos = get_pos(*l_a, 0);
	if (moves->l_size / 2 >= moves->pos)
		moves->ra = moves->pos - 1;
	else if (moves->l_size > 1)
		moves->rra = moves->l_size - moves->pos + 1;
	sort_elem(moves, l_a, NULL);
}

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	get_sort_arr_ps(t_ps_struct *s_psw, int i, int j)
{
	int	mdl;
	int	f;
	int	l;

	f = i;
	l = j;
	mdl = s_psw->int_arr[(f + l) / 2];
	while (f <= l)
	{
		while (s_psw->int_arr[f] < mdl)
			f++;
		while (s_psw->int_arr[l] > mdl)
			l--;
		if (f <= l)
			ft_swap(&s_psw->int_arr[f++], &s_psw->int_arr[l--]);
	}
	if (i < l)
		get_sort_arr_ps(s_psw, i, l);
	if (j > f)
		get_sort_arr_ps(s_psw, f, j);
}
