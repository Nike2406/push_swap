#include "../push_swap.h"

void	three(t_stack **lst)
{
	int	s;
	int	t;

	s = (*lst)->next->value;
	t = (*lst)->next->next->value;
	if ((*lst)->value > s && s < t && (*lst)->value < t)
	{
		sab(lst);
		ft_putstr("sa\n");
	}
	else if ((*lst)->value > s && s > t && (*lst)->value > t)
	{
		sab(lst);
		rrab(lst);
		ft_putstr("sa\n");
		ft_putstr("rra\n");
	}
	else
		three_add(lst, s, t);
}

void	three_add(t_stack **lst, int s, int t)
{
	if ((*lst)->value > s && s < t && (*lst)->value > t)
	{
		rab(lst);
		ft_putstr("ra\n");
	}
	else if ((*lst)->value < s && s > t && (*lst)->value < t)
	{
		sab(lst);
		rab(lst);
		ft_putstr("sa\n");
		ft_putstr("ra\n");
	}
	else if ((*lst)->value < s && s > t && (*lst)->value > t)
	{
		rrab(lst);
		ft_putstr("rra\n");
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

void	fill_arr_list(t_ps_struct *s_psw, t_stack **lst)
{
	int	i;
	int	j;
	int	s;
	char	**tmp_arr;

	i = 0;
	j = 1;
	s_psw->int_arr = ft_calloc(sizeof(int), s_psw->arr_len);
	while (s_psw->argv[j])
	{
		tmp_arr = ft_split(s_psw->argv[j], ' ');
		s = 0;
		while (tmp_arr[s])
		{
			check_isnum(tmp_arr[s]);
			s_psw->int_arr[i] = ft_atoi_ps(tmp_arr[s]);
			ft_lstadd_back_ps(lst, ft_lstnew_ps(ft_atoi_ps(tmp_arr[s])));
			free(tmp_arr[s]);
			s++;
			i++;
		}
		free(tmp_arr);
		j++;
	}
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
