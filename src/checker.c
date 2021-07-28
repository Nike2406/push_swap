#include "../push_swap.h"

int	main(int  argc, char **argv)
{
	(void)argc;
	char	*buf;

	buf = "";
	while (ft_strncmp(argv[2], buf, ft_strlen(argv[2]) + 1))
		{
			ft_putstr("heredoc>");
			if (get_next_line(0, &buf) >= 0 && \
					ft_strncmp(argv[2], buf, \
					ft_strlen(argv[2]) + 1))
			{
				write(1, buf, ft_strlen(buf));
				write(1, "\n", 1);
			}
			free(buf);
		}
	return (0);
}
