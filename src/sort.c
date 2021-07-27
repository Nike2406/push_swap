#include "../push_swap.h"

void	sort_elem(t_move *moves, t_stack **l_a, t_stack **l_b, t_ps_struct *s_psw)
{
	while (moves->ra || moves->rra || moves->rb || moves->rrb)
	{
		if (moves->ra && moves->rb)
		{
			rr(l_a, l_b);
			moves->ra--;
			moves->rb--;
			ft_putstr_ps("rr\n", s_psw);
		}
		else if (moves->rra && moves->rrb)
		{
			rr(l_a, l_b);
			moves->rra--;
			moves->rrb--;
			ft_putstr_ps("rr\n", s_psw);
		}
		else
			sort_elem_add(moves, l_a, l_b, s_psw);
	}
	push_elem(l_a, l_b, s_psw);
}

void	sort_elem_add(t_move *moves, t_stack **l_a, t_stack **l_b, t_ps_struct *s_psw)
{
	if (moves->ra > 0)
	{
		rab(l_a);
		moves->ra--;
		ft_putstr_ps("ra\n", s_psw);
	}
	else if (moves->rb > 0)
	{
		rab(l_b);
		moves->rb--;
		ft_putstr_ps("rb\n", s_psw);
	}
	else if (moves->rra > 0)
	{
		rrab(l_a);
		moves->rra--;
		ft_putstr_ps("rra\n", s_psw);
	}
	else if (moves->rrb > 0)
	{
		rrab(l_a);
		moves->rrb--;
		ft_putstr_ps("rrb\n", s_psw);
	}
}

void	last_sort(t_move *moves, t_stack **l_a, t_ps_struct *s_psw)
{
	init_move(moves);
	moves->l_size = ft_lstsize_ps(*l_a);
	moves->pos = get_pos(*l_a, 1);
	if (moves->l_size / 2 >= moves->pos)
		moves->ra = moves->pos -  1;
	else if (moves->l_size > 1)
		moves->rra = moves->l_size - moves->pos + 1;
	sort_elem(moves, l_a, NULL, s_psw);
}

void	push_elem(t_stack **l_a, t_stack **l_b, t_ps_struct *s_psw)
{
	if (*l_b)
	{
		pab(l_b, l_a);
		ft_putstr_ps("pa\n", s_psw);
	}
}
