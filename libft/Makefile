# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prochell <prochell@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/19 16:33:36 by locus2            #+#    #+#              #
#    Updated: 2021/07/19 20:56:23 by prochell         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a
CFLAGS		= -Wall -Wextra -Werror
CC			= gcc
OBJS	 	= ${SRCS:.c=.o}
OBJS_BNS	= ${SRCS_BNS:.c=.o}
INCLUDE 	= libft.h
SRCS 		= ft_memset.c ft_putstr.c ft_bzero.c \
			ft_memcpy.c ft_memmove.c ft_memchr.c \
			ft_memcmp.c ft_memccpy.c ft_strlen.c \
			ft_strlcpy.c ft_strlcat.c ft_strchr.c \
			ft_strrchr.c ft_strnstr.c ft_strncmp.c \
			ft_atoi.c ft_isalpha.c ft_isdigit.c \
			ft_isalnum.c ft_isascii.c ft_isprint.c \
			ft_toupper.c ft_tolower.c ft_calloc.c \
			ft_strdup.c ft_substr.c ft_strjoin.c \
			ft_strtrim.c ft_itoa.c ft_strmapi.c \
			ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c \
			ft_split.c ft_putchar.c ft_putendl.c \
			ft_putnbr.c ft_strcpy.c

SRCS_BNS	= ft_lstnew.c ft_lstadd_front.c \
			ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
			ft_lstdelone.c ft_lstclear.c \
			ft_lstiter.c ft_lstmap.c

.c.o:
	@${CC} ${CFLAGS} -c $< -o $@

all: ${NAME}

${NAME}: ${OBJS} ${INCLUDE}
	@ar rcs ${NAME} $?

bonus: ${INCLUDE}
	@make OBJS="${OBJS_BNS}" all

norm:
	@norminette *.c
	@norminette *.h

test: all bonus
	@$(CC) $(CFLAGS) main.c $(NAME) && ./a.out | cat -e

lib: all bonus

clean:
	@rm -f ${OBJS}
	@rm -f ${OBJS_BNS}
	@rm -f a.out

fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus
