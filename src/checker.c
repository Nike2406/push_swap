#include "../push_swap.h"

void	checker_moves(char *buf, t_stack **check_a, t_stack **check_b)
{
	if (!(ft_strncmp(buf, "sa", 3)))
		sab(check_a);
	else if (!(ft_strncmp(buf, "sb", 3)))
		sab(check_b);
	else if (!(ft_strncmp(buf, "ss", 3)))
		ss(check_a, check_b);
	else if (!(ft_strncmp(buf, "pa", 3)))
		pab(check_b, check_a);
	else if (!(ft_strncmp(buf, "pb", 3)))
		pab(check_a, check_b);
	else if (!(ft_strncmp(buf, "ra", 3)))
		rab(check_a);
	else if (!(ft_strncmp(buf, "rb", 3)))
		rab(check_b);
	else if (!(ft_strncmp(buf, "rr", 3)))
		rr(check_a, check_b);
	else if (!(ft_strncmp(buf, "rra", 3)))
		rrab(check_a);
	else if (!(ft_strncmp(buf, "rrb", 3)))
		rrab(check_b);
	else if (!(ft_strncmp(buf, "rrr", 3)))
		rrr(check_a, check_b);
	else
		ft_err(1);
}

void	checker_result(t_stack *check_a, t_stack *check_b)
{
	if (check_b != NULL)
		ft_err(1);
	while (check_a->next)
	{
		if (!(check_a->value < check_a->next->value))
		{
			ft_putstr("KO\n");
			exit(1);
		}
		check_a = check_a->next;
	}
	ft_putstr("OK\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	char		*buf;
	t_stack		*check_a;
	t_stack		*check_b;
	t_ps_struct	checker;

	check_a  = NULL;
	check_b  = NULL;
	if (argc < 2)
		return (0);
	checker.arr_len = 0;
	checker.argc = argc;
	checker.argv = argv;
	get_length(&checker);
	fill_arr_list(&checker, &check_a);
	get_sort_arr_ps(&checker, 0, checker.arr_len - 1);
	check_repeat(&checker);
	buf = "";
	while (get_next_line(0, &buf) > 0)
	{
		checker_moves(buf, &check_a, &check_b);
		free(buf);
	}
	free(buf);
	checker_result(check_a, check_b);
	return (0);
}
