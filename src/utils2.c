#include "../push_swap.h"

// get_count_movements(t_stack **l_a, t_stack **l_b)
// {
// 	init_move()
// }

void	ft_putstr_ps(char *a, t_ps_struct *s_psw)
{
	int	i;

	if (!a)
		return ;
	i = 0;
	while (a[i])
	{
		write(1, &a[i], 1);
		i++;
	}
	s_psw->mv_cnt++;
}
