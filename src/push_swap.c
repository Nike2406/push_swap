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
	while (ft_lstsize_ps(*l_a) > 3)
	{
		if ((*l_a)->ind > s_psw->arr_len - 4)
		{
			rab(l_a);
			ft_putstr_ps("ra\n", s_psw);
		}
		else
		{
			pab(l_a, l_b);
			ft_putstr_ps("pb\n", s_psw);
		}
	}
	less_three(l_a, s_psw);
}

void	check(t_ps_struct *s_psw, t_stack **l_a, t_stack **l_b)
{
	// Проверка массива после сортировки
	int i = 0;
	while (i < s_psw->arr_len)
	{
		printf("Array srt - \t%d\n", s_psw->int_arr[i]);
		i++;
	}
	write(1, "\n", 1);
	// Очистка временного массива
	// i = 0;
	// while (int_arr[i])
	// 	int_arr[i++] = 0;
	// free(int_arr);

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
}

int	main(int argc, char **argv)
{
	t_ps_struct	s_psw;
	t_stack *l_a;
	t_stack *l_b;
	t_move	moves;

	l_a = NULL;
	l_b = NULL;
	s_psw.arr_len = 0;
	s_psw.argc = argc;
	s_psw.argv = argv;
	s_psw.mv_cnt = 0;
	get_parse(&s_psw, &l_a, &l_b);
	while (l_b)
		lets_sort(&moves, &l_a, &l_b, &s_psw);
	last_sort(&moves, &l_a, &s_psw);
	// check(&s_psw, &l_a, &l_b);

	// printf("\nMove count - %d\n\n", s_psw.mv_cnt);

	ft_lstclear_ps(&l_a);
	// while (1);

	return (0);
}