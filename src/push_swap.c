/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:28:59 by prochell          #+#    #+#             */
/*   Updated: 2021/07/29 12:29:01 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	get_parse(t_ps_struct *s_psw, t_stack **l_a, t_stack **l_b)
{
	get_length(s_psw);
	fill_arr_list(s_psw, l_a);
	if (ft_lstsize_ps((*l_a)) < 2)
		exit(0);
	if (ft_lstsize_ps((*l_a)) < 3)
	{
		if ((*l_a)->value > (*l_a)->next->value)
		{
			sab(l_a);
			ft_putstr("sa\n");
		}
		exit(0);
	}
	check_sorted(*l_a);
	get_sort_arr_ps(s_psw, 0, s_psw->arr_len - 1);
	check_repeat(s_psw);
	get_index(*l_a, s_psw);
	more_three(s_psw, l_a, l_b);
	three(l_a);
}

void	more_three(t_ps_struct *s_psw, t_stack **l_a, t_stack **l_b)
{
	while (ft_lstsize_ps(*l_a) > 3)
	{
		if ((*l_a)->ind > s_psw->arr_len - 4)
		{
			rab(l_a);
			ft_putstr("ra\n");
		}
		else
		{
			pab(l_a, l_b);
			ft_putstr("pb\n");
		}
	}
}

void	lets_sort(t_move *moves, t_stack **l_a, t_stack **l_b)
{
	int		min_move;
	int		move;
	t_stack	*tmp;
	t_stack	*min_elem;

	min_move = -1;
	tmp = *l_b;
	while (tmp)
	{
		move = cnt_moves(moves, *l_a, *l_b, tmp->ind);
		if (min_move == -1 || move < min_move)
		{
			min_move = move;
			min_elem = tmp;
		}
		tmp = tmp->next;
	}
	min_move = cnt_moves(moves, *l_a, *l_b, min_elem->ind);
	sort_elem(moves, l_a, l_b);
}

int	main(int argc, char **argv)
{
	t_ps_struct	s_psw;
	t_stack		*l_a;
	t_stack		*l_b;
	t_move		moves;

	l_a = NULL;
	l_b = NULL;
	s_psw.arr_len = 0;
	s_psw.argc = argc;
	s_psw.argv = argv;
	s_psw.mv_cnt = 0;
	get_parse(&s_psw, &l_a, &l_b);
	while (l_b)
		lets_sort(&moves, &l_a, &l_b);
	last_sort(&moves, &l_a);
	ft_lstclear_ps(&l_a);
	return (0);
}
