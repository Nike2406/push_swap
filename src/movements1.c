#include "../push_swap.h"

void	sab(t_stack **lst)
{
	t_stack	*first;
	t_stack	*middle;
	t_stack	*last;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	middle = first->next;
	last = middle->next;
	first->next = last;
	middle->next = first;
	*lst = middle;
}

void	ss(t_stack **l_a, t_stack **l_b)
{
	if (*l_a == NULL || (*l_a)->next == NULL)
		return ;
	if (*l_b == NULL || (*l_b)->next == NULL)
		return ;
	sab(l_a);
	sab(l_b);
}

void	pab(t_stack **from, t_stack **to)
{
	t_stack	*tmp;

	if (*from == NULL)
		return ;
	tmp = *from;
	*from = (*from)->next;
	tmp->next = *to;
	*to = tmp;
}

