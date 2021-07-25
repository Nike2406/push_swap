#include "../push_swap.h"

void	less_three(t_stack **l_a)
{
	int	f;
	int	s;
	int	t;

	f = (*l_a)->value;
	s = (*l_a)->next->value;
	t = (*l_a)->next->next->value;
	if (f > s && s < t && f < t)
	{
		sab(l_a);
		ft_putstr("sa\n");
	}
	else if (f > s && s > t && f > t)
	{
		sab(l_a);
		rra(l_a);
		ft_putstr("sa\n");
		ft_putstr("rra\n");
	}
	else
		less_three_add(l_a, f, s, t);
}

void	less_three_add(t_stack **l_a, int f, int s, int t)
{
	if (f > s && s < t && f > t)
	{
		ra(l_a);
		ft_putstr("ra\n");
	}
	else if (f < s && s > t && f < t)
	{
		sab(l_a);
		ra(l_a);
		ft_putstr("sa\n");
		ft_putstr("ra\n");
	}
	else if (f < s && s > t && f > t)
	{
		rra(l_a);
		ft_putstr("rra\n");
	}
}

void	less_five(t_ps_struct *s_psw,t_stack **l_a, t_stack **l_b)
{
	pab(l_a, l_b);
	ft_putstr("pb\n");
	pab(l_a, l_b);
	ft_putstr("pb\n");
	less_three(l_a);
	ft_putstr("-----------\n");
	// Сделать проверку на количество действий!
	while (*l_b != NULL)
	{
		// pab(l_b, l_a);
		// ft_putstr("pa\n");
		if ((*l_a)->ind > (*l_b)->ind)
		{
			pab(l_b, l_a);
			ft_putstr("pa\n");
		}
		else if ((ft_lstlast_ps(*l_a))->value < (*l_b)->value)
		{
			pab(l_b, l_a);
			ft_putstr("pa\n");
			if ((*l_b)->ind <= (s_psw->arr_len / 2))
			{
				rra(l_a);
				ft_putstr("rra\n");
			}
			else
			{
				ra(l_a);
				ft_putstr("ra\n");
			}
		}
		else
		{
			if ((*l_b)->ind >= s_psw->arr_len / 2)
			{
				rra(l_a);
				ft_putstr("rra\n");
			}
			else
			{
				ra(l_a);
				ft_putstr("ra\n");
			}
		}
	}
	while ((*l_a)->ind != 0)
	{
		if ((*l_a)->ind >= s_psw->arr_len / 2)
		{
			rra(l_a);
			ft_putstr("rra\n");
		}
		else
		{
			ra(l_a);
			ft_putstr("ra\n");
		}
	}
}

void	get_index(t_stack *lst, int *arr, t_ps_struct *s_psw)
{
	int		i;

	while (lst)
	{
		i = 0;
		while (i < s_psw->arr_len)
		{
			if (lst->value == arr[i])
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