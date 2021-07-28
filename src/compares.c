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
