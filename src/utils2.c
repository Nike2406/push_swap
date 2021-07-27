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
		if (lst->ind < ind)
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
		return(get_pos(lst, min_index));
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

int	cnt_moves(t_move *moves, t_stack **l_a, t_stack **l_b, int index)
{
	int	total;

	init_move(moves);
	moves->l_size = ft_lstsize_ps(*l_b);
	moves->pos = get_pos(*l_b, index);
	if (moves->l_size / 2 <= moves->pos)
		moves->rb = moves->pos - 1;
	else if (moves->l_size > 1)
		moves->rrb = moves->l_size - moves->pos + 1;
	moves->l_size = ft_lstsize_ps(*l_a);
	moves->pos = get_pos_in(index, *l_a);
	if (moves->l_size / 2 >= moves->pos)
		moves->ra = moves->pos - 1;
	else
		moves->rra = moves->l_size - moves->pos + 1;
	total = moves->ra + moves->rra + moves->rb + moves->rrb;
	// printf("total - %d\n", total);
	return (total);
}

void	lets_sort(t_move *moves, t_stack **l_a, t_stack **l_b, t_ps_struct *s_psw)
{
	int	min_move;
	int	move;
	t_stack	*tmp;
	t_stack	*min_elem;

	min_move = -1;
	tmp = *l_b;
	init_move(moves);
	while (tmp)
	{
		move = cnt_moves(moves, l_a, l_b, tmp->ind);
		if (min_move == -1 || move < min_move)
		{
			min_move = move;
			min_elem = tmp;
		}
		tmp = tmp->next;
	}
	min_move = cnt_moves(moves, l_a, l_b, min_elem->ind);
	sort_elem(moves, l_a, l_b, s_psw);
}

void	ft_putstr_ps(char *a, t_ps_struct *s_psw)
{
	int	i;

	if (!a)
		return ;
	i = 0;
	while (a[i])
	{
		write(1, &a[i], 1);
		i++;
	}
	s_psw->mv_cnt++;
}
