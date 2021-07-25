#include "../push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	get_parse(t_ps_struct *s_psw, t_stack **l_a, t_stack **l_b)
{
	int	*int_arr;
	int	i;
	int	j;
	int	s;
	char	**tmp_arr;

	i = 0;
	j = 1;
	get_length(s_psw);
	int_arr = ft_calloc(sizeof(int), s_psw->arr_len);
	while (s_psw->argv[j])
	{
		tmp_arr = ft_split(s_psw->argv[j], ' ');
		s = 0;
		while (tmp_arr[s])
		{
			int_arr[i] = ft_atoi_ps(tmp_arr[s]);
			// tmp = ft_lstnew_ps(ft_atoi_ps(tmp_arr[s]));
			ft_lstadd_back_ps(l_a, ft_lstnew_ps(ft_atoi_ps(tmp_arr[s])));
			free(tmp_arr[s]);
			s++;
			i++;
			// printf("i - %d\n", i);
			// s_psw->arr_len = i;
		}
		free(tmp_arr);
		j++;
	}

	s_psw->int_arr = int_arr;

	get_sort_ps(s_psw, 0, i - 1);
	check_repeat(s_psw);
	get_index(*l_a, int_arr, s_psw);
	// gr_murkup(l_a, l_b, s_psw);
	less_five(s_psw, l_a, l_b);


	// Проверка массива после сортировки
	i = 0;
	while (i < s_psw->arr_len)
	{
		printf("Array srt - \t%d\n", s_psw->int_arr[i]);
		// printf("Value l_a->value - \t%d\n", l_a->value);
		i++;
	}
	write(1, "\n", 1);
	// Очистка временного массива
	i = 0;
	while (int_arr[i])
		int_arr[i++] = 0;
	free(int_arr);

	// Проверка стека а
	t_stack *current;
	// pb(&l_a, &l_b);
	// pb(&l_a, &l_b);
	// rra(&l_a);
	// rr(&l_a, &l_b);
	current = *l_a;
	while (current != NULL)
	{
		printf("l_a - \t%d\tIndex - %d\n", current->value, current->ind);
		current = current->next;
	}
	ft_putchar('\n');
	// Проверка стека b
	current = *l_b;
	while (current != NULL)
	{
		printf("l_b - \t%d\tIndex - %d\n", current->value, current->ind);
		current = current->next;
	}
	ft_putchar('\n');
	printf("List size a - \t%d\n", ft_lstsize_ps(*l_a));
	printf("List size b - \t%d\n", ft_lstsize_ps(*l_b));
	ft_lstclear_ps(l_a);
}

void	get_sort_ps(t_ps_struct *s_psw, int i, int j)
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
		get_sort_ps(s_psw, i, l);
	if (j > f)
		get_sort_ps(s_psw, f, j);
}

int	main(int argc, char **argv)
{
	// t_push_swap	s_a;
	// t_push_swap	s_b;
	t_ps_struct	s_psw;
	t_stack *l_a;
	t_stack *l_b;

	l_a = NULL;
	l_b = NULL;
	s_psw.arr_len = 0;
	check_isnum(argc, argv);
	s_psw.argc = argc;
	s_psw.argv = argv;
	get_parse(&s_psw, &l_a, &l_b);
	// while (1);

	return (0);
}