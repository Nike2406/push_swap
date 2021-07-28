#include "../push_swap.h"

void	ft_err(int	code)
{
	if (code == 1)
		ft_putstr("Error\n");
	else
		ft_putstr("Unexpected error.\n");
	exit(code);
}

void	check_isnum(char *argv)
{
	int	j;
	int	f;

	j = 0;
	f = 0;
	while (argv[j])
	{
		if (!(argv[j] >= '0' && argv[j] <= '9'))
		{
			if (argv[j] == '-' && !f && !j)
			{
				f++;
				if (!(argv[j + 1] >= '0' && argv[j + 1] <= '9'))
					ft_err(1);
			}
			else
				ft_err(1);
		}
		j++;
	}
}

void	check_sorted(t_stack *lst)
{
	while (lst->next)
	{
		if (lst->value < lst->next->value)
			lst = lst->next;
		else
			return ;
	}
	exit(0);
}

void	check_repeat(t_ps_struct *s_psw)
{
	int	i;

	i = 0;
	while (i < s_psw->arr_len - 1)
	{
		if (s_psw->int_arr[i] == s_psw->int_arr[i + 1])
			ft_err(1);
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
			ft_err(1);
		total = (total * 10) + (str[i] - 48);
		i++;
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (total * min);
	}
	return (0);
}

void	get_length(t_ps_struct *s_psw)
{
	int	i;
	int	j;

	i = 1;
	char	**tmp;
	while (s_psw->argv[i])
	{
		tmp = ft_split(s_psw->argv[i], ' ');
		j = 0;
		while (tmp[j])
		{
			s_psw->arr_len++;
			j++;
		}
		i++;
		j = 0;
		while (tmp[j])
		{
			free(tmp[j]);
			j++;
		}
		free(tmp);
	}
}
