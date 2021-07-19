NAME 		= push_swap
FLAGS		= -Wall -Wextra -Werror
CFLAGS		= $(FLAGS) -I.
CC			= gcc

ifeq ($(MAKECMDGOALS),bonus)
	OBJS = $(SRCS_BONUS:%.c=%.o)
else
	OBJS = $(SRCS:%.c=%.o)
endif

LIBFT_OBJS	= $(LIBFT:%.c=%.o)
SRCS 		= src/push_swap.c \
			src/utils.c \
			src/movements.c \
			src/lst_functions.c \
INCLUDE		= push_swap.h
LIBFT_A		= libft/libft.a

.PHONY: all clean fclean re bonus libft norm

.o: .c $(INCLUDE)
	$(CC) $(CFLAGS) $< -o $@

all: libft $(NAME)

${NAME}: $(OBJS) $(INCLUDE)
	$(CC) $(OBJS) $(LIBFT_A) -o $(NAME)

bonus: libft $(NAME)

norm:
	norminette $(SRCS)
	norminette $(SRCS_BONUS)
	norminette $(INCLUDE)
	make -C libft/ norm

libft:
	make lib -C libft

clean:
	rm -f src/*.o
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all
