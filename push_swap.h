#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include "./get_next_line/get_next_line.h"
// Убрать!
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				ind;
	struct s_stack	*next;
}	t_stack;

typedef struct s_bonus
{
	char			*content;
	struct s_bonus	*next;
}	t_bonus;

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
void		init_move(t_move *moves);
void		lets_sort(t_move *moves, t_stack **l_a, t_stack **l_b, \
	t_ps_struct *s_psw);
int			cnt_moves(t_move *moves, t_stack *l_a, t_stack *l_b, int index);
int			get_pos(t_stack *lst, int index);
int			get_pos_in(int index, t_stack *lst);
int			get_min_ind(t_stack *lst);
void		sort_elem(t_move *moves, t_stack **l_a, t_stack **l_b, \
	t_ps_struct *s_psw);
void		sort_elem_add(t_move *moves, t_stack **l_a, t_stack **l_b, \
	t_ps_struct *s_psw);
void		push_elem(t_stack **l_a, t_stack **l_b, t_ps_struct *s_psw);
void		last_sort(t_move *moves, t_stack **l_a, t_ps_struct *s_psw);

void		ft_err(int	code);
void		check_isnum(char *argv);
void		check_repeat(t_ps_struct *s_psw);
void		check_sorted(t_stack *lst);
int			ft_atoi_ps(const char *str);
int			ft_limits_ps(long long total, char const s, int sign);
void		ft_putstr_ps(char *a, t_ps_struct *s_psw);
void		get_index(t_stack *lst, t_ps_struct *s_spw);
void		less_five(t_ps_struct *s_psw, t_stack **l_a, t_stack **l_b);
void		three(t_stack **l_a, t_ps_struct *s_psw);
void		three_add(t_stack **l_a, int s, int t, t_ps_struct *s_psw);

void		ft_lstadd_back_ps(t_stack **lst, t_stack *new);
void		ft_lstadd_front_ps(t_stack **lst, t_stack *new);
void		ft_lstclear_ps(t_stack **lst);
t_stack		*ft_lstlast_ps(t_stack *lst);
t_stack		*ft_lstnew_ps(int content);
int			ft_lstsize_ps(t_stack *lst);

void		ft_lstadd_back_b_ps(t_bonus **lst, t_bonus *new);
t_bonus		*ft_lstlast_b_ps(t_bonus *lst);
t_bonus		*ft_lstnew_b_ps(char *content);
int			ft_lstsize_b_ps(t_bonus *lst);
// void		fill_arr_list_b(t_ps_struct *s_psw, t_bonus **lst);

void		sab(t_stack **lst);
void		ss(t_stack **l_a, t_stack **l_b);
void		pab(t_stack **from, t_stack **to);
void		rab(t_stack **lst);
void		rr(t_stack **l_a, t_stack **l_b);
void		rrab(t_stack **lst);
void		rrr(t_stack **l_a, t_stack **l_b);

void	check(t_ps_struct *s_psw, t_stack **l_a, t_stack **l_b);

#endif
