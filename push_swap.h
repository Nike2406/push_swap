#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"

typedef struct s_push_swap
{
	int				content;
	int				mvs;
	int				ind;
	unsigned char	des;
	struct s_push_swap	*next;
}	t_push_swap;

typedef struct s_ps_struct
{
	char	**argv;
	int		argc;
	int		*int_arr;
	int		arr_len;
}	t_ps_struct;

void	get_parse(t_ps_struct *s_psw);
void	get_sort_ps(t_ps_struct *s_psw, int i, int j);
void	ft_swap(int *a, int *b);
void	ft_err(int	code);
void	check_isnum(int argc, char **argv);
void	check_repeat(int argc, char **argv);

#endif
