#include "../push_swap.h"

void	rra(t_stack **l_a)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	if (*l_a == NULL || (*l_a)->next == NULL)
		return ;
	first = *l_a;
	tmp = *l_a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = first;
	*l_a = last;
	ft_putstr("rra\n");
}

void	rrb(t_stack **l_b)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	if (*l_b == NULL || (*l_b)->next == NULL)
		return ;
	first = *l_b;
	tmp = *l_b;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = first;
	*l_b = last;
	ft_putstr("rrb\n");
}

void	rrr(t_stack **l_a, t_stack **l_b)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	if (*l_a == NULL || (*l_a)->next == NULL || \
		*l_b == NULL || (*l_b)->next == NULL)
		return ;
	first = *l_a;
	tmp = *l_a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = first;
	*l_a = last;
	first = *l_b;
	tmp = *l_b;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = first;
	*l_b = last;
	ft_putstr("rrr\n");
}
