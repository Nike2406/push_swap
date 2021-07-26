#include "../push_swap.h"

void	less_three(t_stack **lst, t_ps_struct *s_psw)
{
	int	s;
	int	t;

	s = (*lst)->next->value;
	t = (*lst)->next->next->value;
	if ((*lst)->value > s && s < t && (*lst)->value < t)
	{
		sab(lst);
		ft_putstr_ps("sa\n", s_psw);
	}
	else if ((*lst)->value > s && s > t && (*lst)->value > t)
	{
		sab(lst);
		rrab(lst);
		ft_putstr_ps("sa\n", s_psw);
		ft_putstr_ps("rra\n", s_psw);
	}
	else
		less_three_add(lst, s, t, s_psw);
}

void	less_three_add(t_stack **lst, int s, int t, t_ps_struct *s_psw)
{
	if ((*lst)->value > s && s < t && (*lst)->value > t)
	{
		rab(lst);
		ft_putstr_ps("ra\n", s_psw);
	}
	else if ((*lst)->value < s && s > t && (*lst)->value < t)
	{
		sab(lst);
		rab(lst);
		ft_putstr_ps("sa\n", s_psw);
		ft_putstr_ps("ra\n", s_psw);
	}
	else if ((*lst)->value < s && s > t && (*lst)->value > t)
	{
		rrab(lst);
		ft_putstr_ps("rra\n", s_psw);
	}
}

void	less_five(t_ps_struct *s_psw, t_stack **l_a, t_stack **l_b)
{
	s_psw->mv_cnt = 0;
	while ((*l_a)->next->next->next != NULL)
	{
		if ((*l_a)->ind < s_psw->arr_len / 2)
		{
			pab(l_a, l_b);
			ft_putstr_ps("pb\n", s_psw);
		}
		else
		{
			rab(l_a);
			ft_putstr_ps("ra\n", s_psw);
		}
	}
	less_three(l_a, s_psw);
	if (((*l_b)->ind) < ((*l_b)->next->ind))
	{
		rab(l_b);
		ft_putstr_ps("rb\n", s_psw);
	}
	pab(l_b, l_a);
	ft_putstr_ps("pa\n", s_psw);
	pab(l_b, l_a);
	ft_putstr_ps("pa\n", s_psw);
	printf("\nMove count - %d\n\n", s_psw->mv_cnt);
}

void	get_index(t_stack *lst, t_ps_struct *s_psw)
{
	int		i;

	while (lst)
	{
		i = 0;
		while (i < s_psw->arr_len)
		{
			if (lst->value == s_psw->int_arr[i])
			{
				lst->ind = i;
				break;
			}
			else
				i++;
		}
		lst = lst->next;
	}
}