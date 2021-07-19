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
void	ft_lstclear_ps(t_stack **lst, void (*del)(void *));
t_stack	*ft_lstlast_ps(t_stack *lst);
t_stack	*ft_lstnew_ps(void *content);

#endif
