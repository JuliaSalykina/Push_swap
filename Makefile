# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mannette <mannette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/26 17:50:44 by mannette          #+#    #+#              #
#    Updated: 2020/03/03 21:57:10 by mannette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_PUSH = push_swap
NAME_CHECK = checker
LIB_PATH = ./libft/
HEADER = push_swap.h

SRC = valid.c list.c check_sort.c command.c command2.c common.c double_com.c \
		ft_clean.c mas.c print.c small.c sort.c \

OBJS = $(SRC:.c=.o)

LIB = ./libft/libft.a

.PHONY: all clean fclean re force norm

all: $(LIB) $(NAME_CHECK) $(NAME_PUSH)

$(LIB): force
	make -C $(LIB_PATH)

$(NAME_PUSH): $(OBJS) push_swap.c
	gcc -Wall -Werror -Wextra $(OBJS) -I . -L ./libft -lft push_swap.c -o $@

$(NAME_CHECK): $(OBJS) checker.c
	gcc -Wall -Werror -Wextra $(OBJS) -I . -L ./libft -lft checker.c -o $@

./%.o: ./%.c $(HEADER)
	gcc -Wall -Wextra -Werror -I . -c $< -o $@

norm:
	norminette

clean:
	rm -f $(OBJS)
	make clean -C $(LIB_PATH)

fclean: clean
	/bin/rm -f $(NAME_PUSH) $(NAME_CHECK)
	/bin/rm -f $(LIB)

re: fclean all