#include "../push_swap.h"

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
