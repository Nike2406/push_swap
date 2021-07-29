/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prochell <prochell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 12:29:21 by prochell          #+#    #+#             */
/*   Updated: 2021/07/29 12:30:42 by prochell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_pos(t_stack *lst, int index)
{
	int		pos;

	pos = 1;
	while (lst->ind != index)
	{
		pos++;
		lst = lst->next;
	}
	return (pos);
}

int	get_min_ind(t_stack *lst)
{
	int	ind;

	ind = 0;
	while (lst)
	{
		if (ind == 0)
			ind = lst->ind;
		else if (lst->ind < ind)
			ind = lst->ind;
		lst = lst->next;
	}
	return (ind);
}

int	get_pos_in(int index, t_stack *lst)
{
	int		pos;
	int		prev;
	int		next;
	int		min_index;
	t_stack	*tmp;

	pos = 1;
	prev = lst->ind;
	tmp = lst->next;
	next = tmp->ind;
	min_index = get_min_ind(lst);
	if (index < min_index)
		return (get_pos(lst, min_index));
	while (1)
	{
		pos++;
		if (prev < index && next > index)
			return (pos);
		prev = tmp->ind;
		if (!tmp->next)
			tmp = lst;
		else
			tmp = tmp->next;
		next = tmp->ind;
	}
}

int	cnt_moves(t_move *moves, t_stack *l_a, t_stack *l_b, int index)
{
	int	total;

	init_move(moves);
	moves->l_size = ft_lstsize_ps(l_b);
	moves->pos = get_pos(l_b, index);
	if (moves->l_size / 2 >= moves->pos)
		moves->rb = moves->pos - 1;
	else if (moves->l_size > 1)
		moves->rrb = moves->l_size - moves->pos + 1;
	moves->l_size = ft_lstsize_ps(l_a);
	moves->pos = get_pos_in(index, l_a);
	if (moves->l_size / 2 >= moves->pos)
		moves->ra = moves->pos - 1;
	else
		moves->rra = moves->l_size - moves->pos + 1;
	total = moves->ra + moves->rra + moves->rb + moves->rrb;
	total_optimize(&total, moves);
	return (total);
}

void	total_optimize(int *total, t_move *moves)
{
	int	i;

	i = moves->ra;
	if (moves->ra > moves->rb)
		i = moves->rb;
	while (i)
	{
		total--;
		i--;
	}
	i = moves->rra;
	if (moves->rra > moves->rrb)
		i = moves->rrb;
	while (i)
	{
		total--;
		i--;
	}
}
