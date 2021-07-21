#include "../push_swap.h"

void	ra(t_stack **l_a)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	if (*l_a == NULL || (*l_a)->next == NULL)
		return ;
	tmp = *l_a;
	first = (*l_a)->next;
	last = *l_a;
	while (last->next != NULL)
		last = last->next;
	tmp->next = NULL;
	last->next = tmp;
	*l_a = first;
	ft_putstr("ra\n");
}

void	rb(t_stack **l_b)
{
	t_stack *first;
	t_stack *last;
	t_stack *tmp;

	if (*l_b == NULL || (*l_b)->next == NULL)
		return ;
	tmp = *l_b;
	first = (*l_b)->next;
	last = *l_b;
	while (last->next != NULL)
		last = last->next;
	tmp->next = NULL;
	last->next = tmp;
	*l_b = first;
	ft_putstr("rb\n");
}

void	rr(t_stack **l_a, t_stack **l_b)
{
	t_stack	*first;
	t_stack	*last;
	t_stack	*tmp;

	if (*l_a == NULL || (*l_a)->next == NULL || \
		*l_b == NULL || (*l_b)->next == NULL)
		return ;
	tmp = *l_a;
	first = (*l_a)->next;
	last = *l_a;
	while (last->next != NULL)
		last = last->next;
	tmp->next = NULL;
	last->next = tmp;
	*l_a = first;
	tmp = *l_b;
	first = (*l_b)->next;
	last = *l_b;
	while (last->next != NULL)
		last = last->next;
	tmp->next = NULL;
	last->next = tmp;
	*l_b = first;
	ft_putstr("rb\n");
}
