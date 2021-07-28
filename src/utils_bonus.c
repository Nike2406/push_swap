#include "../push_swap.h"

void	ft_lstadd_back_b_ps(t_bonus **lst, t_bonus *new)
{
	t_bonus	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast_b_ps(*lst);
	tmp->next = new;
}

t_bonus	*ft_lstlast_b_ps(t_bonus *lst)
{
	t_bonus	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_bonus	*ft_lstnew_b_ps(char *content)
{
	t_bonus	*nel;

	nel = (t_bonus *)malloc(sizeof(t_bonus));
	if (!nel)
		return (NULL);
	nel->content = content;
	nel->next = NULL;
	return (nel);
}

int	ft_lstsize_b_ps(t_bonus *lst)
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

