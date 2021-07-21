#include "../push_swap.h"

void	ft_err(int	code)
{
	if (code == 1)
		ft_putstr("Error\n");
	else if (code == 2)
		ft_putstr("Error\n");
	else if (code == 3)
		ft_putstr("Error\n");
	else if (code == 4)
	ft_putstr("Error\n");
	else
		ft_putstr("Unexpected error.\n");
	exit(code);
}

void	check_isnum(int argc, char **argv)
{
	int			i;
	int			j;

	i = 1;
	// Проверка на аргументы (?)
	(void)argc;
	// if (argc < 3)
	// 	ft_err(1);

	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9'))
				if (argv[i][j] == '-')
					if (!(argv[i][j + 1] >= '0' && argv[i][j + 1] <= '9'))
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

int	ft_limits_ps(long long total, char const s, int sign)
{
	long long	min;
	long long	max;

	max = (total * 10 + (s - '0')) * sign;
	if (max > 2147483647)
		return (0);
	min = (total * 10 + (s - '0')) * sign;
	if (min < -2147483648)
		return (-1);
	return (1);
}

int	ft_atoi_ps(const char *str)
{
	int				i;
	int				min;
	long long		total;
	int				lim;

	i = 0;
	min = 1;
	total = 0;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			min = -min;
	while (str[i] >= '0' && str[i] <= '9')
	{
		lim = ft_limits_ps(total, str[i], min);
		if (lim < 1)
			ft_err(4);
		total = (total * 10) + (str[i] - 48);
		i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (total * min);
	}
	return (0);
}
