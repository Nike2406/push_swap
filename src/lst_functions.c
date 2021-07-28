#include "../push_swap.h"

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast_ps(*lst);
	tmp->next = new;
}

void	ft_lstclear_ps(t_stack **lst)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = *lst;
		*lst = (*lst)->next;
		free(tmp);
	}
}

t_stack	*ft_lstlast_ps(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_stack	*ft_lstnew_ps(int content)
{
	t_stack	*nel;

	nel = (t_stack *)malloc(sizeof(t_stack));
	if (!nel)
		return (NULL);
	nel->value = content;
	nel->next = NULL;
	return (nel);
}

int	ft_lstsize_ps(t_stack *lst)
{
	unsigned int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
