ifeq ($(MAKECMDGOALS),bonus)
	NAME = checker
else
	NAME = push_swap
endif
FLAGS		= -Wall -Wextra -Werror
CFLAGS		= $(FLAGS) -I. -g
CC			= gcc

ifeq ($(MAKECMDGOALS),bonus)
	OBJS = $(SRCS_BONUS:%.c=%.o)
else
	OBJS = $(SRCS:%.c=%.o)
endif

LIBFT_OBJS	= $(LIBFT:%.c=%.o)
SRCS 		= src/push_swap.c \
			src/utils1.c \
			src/utils2.c \
			src/movements1.c \
			src/movements2.c \
			src/lst_functions.c \
			src/compares.c \
			src/sort.c \
			src/var_checks.c
SRCS_BONUS	= src/checker.c \
			src/utils1.c \
			src/utils2.c \
			src/movements1.c \
			src/movements2.c \
			src/lst_functions.c \
			src/compares.c \
			src/sort.c \
			src/utils_bonus.c \
			src/var_checks.c \
			get_next_line/get_next_line.c
INCLUDE		= push_swap.h \
			get_next_line/get_next_line.h
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
	rm -f get_next_line/*.o
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	rm -f checker
	rm -f push_swap
	rm -rf a.out*
	rm -rf */a.out*
	rm -rf *.gch
	rm -rf */*.gch
	rm -f libft/libft.a

re: fclean all
