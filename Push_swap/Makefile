# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 14:14:23 by ael-asri          #+#    #+#              #
#    Updated: 2022/01/16 13:39:42 by ael-asri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = push_swap

SRCS = push_swap.c push_swap_utils.c push_swap_lis_utils.c errors.c sorting.c actions.c

CSRCS = Checker_utils/checker_utils.c Checker_utils/get_next_line.c Checker_utils/get_next_line_utils.c Checker_utils/get_next_line.h
 
OBJS = $(SRCS:.c=.o)

COBJS = $(CSRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(COBJS)

.c.o:
	gcc $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re