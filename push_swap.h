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
	int		mv_cnt;
}	t_ps_struct;

typedef struct s_move
{
	int	l_size;
	int	pos;
	int	ra;
	int	rb;
	int	rra;
	int	rrb;
}	t_move;

void		get_parse(t_ps_struct *s_psw, t_stack **l_a, t_stack **l_b);
void		get_sort_arr_ps(t_ps_struct *s_psw, int i, int j);
void		ft_swap(int *a, int *b);
void		get_length(t_ps_struct *s_psw);
void		fill_arr_list(t_ps_struct *s_psw, t_stack **lst);

void		ft_err(int	code);
void		check_isnum(char *argv);
void		check_repeat(t_ps_struct *s_psw);
int			ft_atoi_ps(const char *str);
int			ft_limits_ps(long long total, char const s, int sign);
void		ft_putstr_ps(char *a, t_ps_struct *s_psw);
void		get_index(t_stack *lst, t_ps_struct *s_spw);
void		less_five(t_ps_struct *s_psw, t_stack **l_a, t_stack **l_b);
void		less_three(t_stack **l_a, t_ps_struct *s_psw);
void		less_three_add(t_stack **l_a, int s, int t, t_ps_struct *s_psw);

void		ft_lstadd_back_ps(t_stack **lst, t_stack *new);
void		ft_lstadd_front_ps(t_stack **lst, t_stack *new);
void		ft_lstclear_ps(t_stack **lst);
t_stack		*ft_lstlast_ps(t_stack *lst);
t_stack		*ft_lstnew_ps(int content);
int			ft_lstsize_ps(t_stack *lst);

void		sab(t_stack **lst);
void		ss(t_stack **l_a, t_stack **l_b);
void		pab(t_stack **from, t_stack **to);
void		rab(t_stack **lst);
void		rr(t_stack **l_a, t_stack **l_b);
void		rrab(t_stack **lst);
void		rrr(t_stack **l_a, t_stack **l_b);

#endif
