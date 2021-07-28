#include "../push_swap.h"

// void	get_args(t_bonus **lst, char argv)
// {

// }

int	main(int argc, char **argv)
{
	(void)argc;
	char		*buf;
	t_bonus		*mv_check;
	// t_stack		*num_check;
	t_ps_struct	checker;

	if (argc < 2)
		return (0);
	checker.arr_len = 0;
	checker.argc = argc;
	checker.argv = argv;
	checker.mv_cnt = 0;
	get_length(&checker);
	fill_arr_list(&checker, NULL);

	buf = "";
	mv_check = NULL;
	while (ft_strncmp(argv[1], buf, ft_strlen(argv[1]) + 1))
	{
		ft_putstr("heredoc>");
		if (get_next_line(0, &buf) >= 0)
		{
			ft_lstadd_back_b_ps(&mv_check, ft_lstnew_b_ps(buf));
		}
	}

	// Проверка стека
	t_bonus	*current;
	current = mv_check;
	while (current != NULL)
	{
		printf("Content - \t%s\n", current->content);
		current = current->next;
	}
	free(buf);
	return (0);
}
