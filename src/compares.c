#include "../push_swap.h"

// void	first_compare(t_stack *l_a, t_stack *l_b)
// {

// }

void		get_index(t_stack *lst, int *arr, t_ps_struct *s_psw)
{
	int		i;

	while (lst)
	{
		i = 0;
		while (i < s_psw->arr_len)
		{
			if (lst->value == arr[i])
			{
				lst->ind = i;
				break;
			}
			else
				i++;
		}
		lst = lst->next;
	}
}