#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
// Убрать!
# include <stdio.h>


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

void		get_parse(t_ps_struct *s_psw, t_stack **l_a, t_stack **l_b);
void		get_sort_ps(t_ps_struct *s_psw, int i, int j);
void		ft_swap(int *a, int *b);
void		get_length(t_ps_struct *s_psw);

// void		ft_err(int	code);
void		check_isnum(int argc, char **argv);
void		check_repeat(t_ps_struct *s_psw);
int			ft_atoi_ps(const char *str);
int			ft_limits_ps(long long total, char const s, int sign);
void		get_index(t_stack *lst, int *arr, t_ps_struct *s_spw);
int			gr_murkup(t_stack *lst);
void		less_five(t_stack **l_a, t_stack **l_b);
void		less_three(t_stack **l_a);
void		less_three_add(t_stack **l_a, int f, int s, int t);

void		ft_lstadd_back_ps(t_stack **lst, t_stack *new);
void		ft_lstadd_front_ps(t_stack **lst, t_stack *new);
void		ft_lstclear_ps(t_stack **lst);
t_stack		*ft_lstlast_ps(t_stack *lst);
t_stack		*ft_lstnew_ps(int content);
int			ft_lstsize_ps(t_stack *lst);

void		sab(t_stack **lst);
void		ss(t_stack **l_a, t_stack **l_b);
void		pab(t_stack **from, t_stack **to);
void		ra(t_stack **l_a);
void		rb(t_stack **l_b);
void		rr(t_stack **l_a, t_stack **l_b);
void		rra(t_stack **l_a);
void		rrb(t_stack **l_b);
void		rrr(t_stack **l_a, t_stack **l_b);

#endif
