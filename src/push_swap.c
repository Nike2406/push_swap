#include "../push_swap.h"
// Убрать!
#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	get_parse(t_ps_struct *s_psw, t_stack *l_a, t_stack *l_b)
{
	int	*int_arr;
	int	i;
	int	j;

	i = 0;
	j = 1;

	int_arr = ft_calloc(sizeof(int), (s_psw->argc - 1));
	l_a = NULL;
	l_b = NULL;
	while (s_psw->argv[j])
	{
		int_arr[i] = ft_atoi(s_psw->argv[j]);
		ft_lstadd_back_ps(&l_a, ft_lstnew_ps(ft_atoi(s_psw->argv[j])));
		i++;
		j++;
	}
	s_psw->arr_len = j;
	s_psw->int_arr = int_arr;
	get_sort_ps(s_psw, 0, i - 1);
	// // Проверка массива после сортировки
	// i = 0;
	// while (i < s_psw->arr_len - 1)
	// {
	// 	printf("Array srt - \t%d\n", s_psw->int_arr[i]);
	// 	// printf("Value l_a->value - \t%d\n", l_a->value);
	// 	i++;
	// }
	free(int_arr);

	// Проверка стека а
	t_stack *current;
	current = l_a;
	while (current != NULL)
	{
		printf("l_a - \t%d\n", current->value);
		current = current->next;
	}
	pb(l_a, l_b);
	current = l_b;
	while (current != NULL)
	{
		printf("l_b - \t%d\n", current->value);
		current = current->next;
	}
	printf("List size a - \t%d\n", ft_lstsize_ps(l_a));
	printf("List size b - \t%d\n", ft_lstsize_ps(l_b));
	// printf("List - \t%p\n", &l_a);
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
	t_stack l_a;
	t_stack l_b;

	// (void)s_a;
	// (void)s_b;

	check_isnum(argc, argv);

	s_psw.argc = argc;
	s_psw.argv = argv;

	get_parse(&s_psw, &l_a, &l_b);
	check_repeat(&s_psw);
	// while (1);

	return (0);
}