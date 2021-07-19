#include "../push_swap.h"

void	ft_err(int	code)
{
	if (code == 1)
		ft_putstr("Please, add more data.\n");
	else if (code == 2)
		ft_putstr("Only numbers are allow!\n");
	else if (code == 3)
		ft_putstr("Parametres must not be repeated!\n");
	else
		ft_putstr("Unexpected error.\n");
	exit(code);
}

void	check_isnum(int argc, char **argv)
{
	int			i;
	int			j;

	i = 1;
	if (argc < 3)
		ft_err(1);
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				ft_err(2);
			j++;
		}
		i++;
	}
}

void	check_repeat(t_ps_struct *s_psw)
{
	int	i;

	i = 0;
	while (s_psw->int_arr[i] < s_psw->arr_len - 1)
	{
		if (s_psw->int_arr[i] == s_psw->int_arr[i + 1])
			ft_err(3);
		i++;
	}
}
