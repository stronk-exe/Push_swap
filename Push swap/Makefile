# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 10:49:28 by ael-asri          #+#    #+#              #
#    Updated: 2022/02/08 18:51:38 by ael-asri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

SRCS = push_swap.c\
		push_swap_utils.c\
		push_swap_list_utils.c\
		errors.c\
		sorting.c\
		actions.c\
		actions2.c\
		actions3.c\
		smallsort.c\
		bigsort.c\
		get_index.c\
		minmax_indexes.c\
		minmax_values.c\
		a_to_b.c\
		b_to_a.c

CSRCS = checker_utils/checker.c\
		checker_utils/checker_utils.c\
		checker_utils/get_next_line.c\
		checker_utils/get_next_line_utils.c\
		push_swap_utils.c\
		push_swap_list_utils.c\
		errors.c\
		sorting.c\
		actions.c\
		actions2.c\
		actions3.c\
		smallsort.c\
		bigsort.c\
		get_index.c\
		minmax_indexes.c\
		minmax_values.c\
		a_to_b.c\
		b_to_a.c
		

OBJS = $(SRCS:.c=.o)

COBJS = $(CSRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
		cc $(CFLAGS) $^ -o $@
		
bonus : $(BONUS)

$(BONUS): $(COBJS)
		cc $(CFLAGS) $^ -o $@

clean:
	rm -f $(OBJS) $(COBJS)

fclean: clean
		rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: all clean fclean re bonus