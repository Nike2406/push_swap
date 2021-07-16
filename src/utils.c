#include "../push_swap.h"

void	ft_err(int	code)
{
	if (code == 1)
		ft_putstr("Please, add more data.\n");
	else if (code == 2)
		ft_putstr("Only digits are allow!\n");
	else
		ft_putstr("Unexpected error.\n");
	exit(code);
}

void	check_args(int argc, char **argv)
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
