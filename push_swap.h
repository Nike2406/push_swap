#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"

typedef struct s_push_swap
{
	int				val;
	int				order;
	int				flag;
	struct s_push_swap	*nxt;
}	t_push_swap;

typedef struct s_ps_struct
{
	char	**argv;
	int		argc;
	int		*int_arr;
}	t_ps_struct;

void	get_parse(t_ps_struct *s_psw);
void	get_sort_pw(t_ps_struct *s_psw, int i, int j);
void	ft_swap(int *a, int *b);

#endif
