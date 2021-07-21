#include "../push_swap.h"

void	sa(t_stack *l_a)
{
	int	tmp;

	if (l_a == NULL || l_a->next == NULL)
		return ;
	tmp = l_a->value;
	l_a->value = l_a->next->value;
	l_a->next->value = tmp;
	ft_putstr("sa\n");
}

void	sb(t_stack *l_b)
{
	int	tmp;

	if (l_b == NULL || l_b->next == NULL)
		return ;
	tmp = l_b->value;
	l_b->value = l_b->next->value;
	l_b->next->value = tmp;
	ft_putstr("sb\n");
}

void	ss(t_stack *l_a, t_stack *l_b)
{
	int	tmp;

	if (l_a == NULL || l_a->next == NULL)
		return ;
	if (l_b == NULL || l_b->next == NULL)
		return ;
	tmp = l_a->value;
	l_a->value = l_a->next->value;
	l_a->next->value = tmp;
	tmp = l_b->value;
	l_b->value = l_b->next->value;
	l_b->next->value = tmp;
	ft_putstr("ss\n");
}

void	pa(t_stack **l_a, t_stack **l_b)
{
	t_stack	*tmp;

	if (*l_b == NULL)
		return ;
	tmp = *l_b;
	*l_b = (*l_b)->next;
	tmp->next = *l_a;
	*l_a = tmp;
	ft_putstr("pa\n");
}

void	pb(t_stack **l_a, t_stack **l_b)
{
	t_stack	*tmp;

	if (*l_a == NULL)
		return ;
	tmp = *l_a;
	*l_a = (*l_a)->next;
	tmp->next = *l_b;
	*l_b = tmp;
	ft_putstr("pb\n");
}
