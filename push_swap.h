#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				ind;
	struct s_stack	*next;
}	t_stack;

typedef struct s_ps_struct
{
	char	**argv;
	int		argc;
	int		*int_arr;
	int		*ps_arr;
	int		arr_len;
}	t_ps_struct;

void	get_parse(t_ps_struct *s_psw, t_stack *l_a, t_stack *l_b);
void	get_sort_ps(t_ps_struct *s_psw, int i, int j);
void	ft_swap(int *a, int *b);

void	ft_err(int	code);
void	check_isnum(int argc, char **argv);
void	check_repeat(t_ps_struct *s_psw);

void	ft_lstadd_back_ps(t_stack **lst, t_stack *new);
void	ft_lstadd_front_ps(t_stack **lst, t_stack *new);
void	ft_lstclear_ps(t_stack **lst, void (*del)(int));
t_stack	*ft_lstlast_ps(t_stack *lst);
t_stack	*ft_lstnew_ps(int content);
int		ft_lstsize_ps(t_stack *lst);

void	sa(t_stack *l_a);
void	sb(t_stack *l_b);
void	ss(t_stack *l_a, t_stack *l_b);
void	pa(t_stack **l_a, t_stack **l_b);
void	pb(t_stack **l_a, t_stack **l_b);
void	ra(t_stack **l_a);
void	rb(t_stack **l_b);
void	rr(t_stack **l_a, t_stack **l_b);
void	rra(t_stack **l_a);
void	rrb(t_stack **l_b);
void	rrr(t_stack **l_a, t_stack **l_b);

#endif
