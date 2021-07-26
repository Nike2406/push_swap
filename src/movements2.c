#include "../push_swap.h"

void	rab(t_stack **lst)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	tmp = *lst;
	first = (*lst)->next;
	last = *lst;
	while (last->next != NULL)
		last = last->next;
	tmp->next = NULL;
	last->next = tmp;
	*lst = first;
}

void	rr(t_stack **l_a, t_stack **l_b)
{
	if (*l_a == NULL || (*l_a)->next == NULL || \
		*l_b == NULL || (*l_b)->next == NULL)
		return ;
	rab(l_a);
	rab(l_b);
}

void	rrab(t_stack **lst)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	first = *lst;
	tmp = *lst;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = first;
	*lst = last;
}

void	rrr(t_stack **l_a, t_stack **l_b)
{
	if (*l_a == NULL || (*l_a)->next == NULL || \
		*l_b == NULL || (*l_b)->next == NULL)
		return ;
	rrab(l_a);
	rrab(l_b);
}
