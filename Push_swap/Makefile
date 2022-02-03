# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/02 10:49:28 by ael-asri          #+#    #+#              #
#    Updated: 2022/02/02 15:43:02 by ael-asri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS = push_swap.c push_swap_utils.c push_swap_list_utils.c errors.c sorting.c special_sorting.c actions.c actions2.c actions3.c smallsort.c bigsort.c get_index.c

#CSRCS = Checker_utils/checker_utils.c Checker_utils/get_next_line.c Checker_utils/get_next_line_utils.c Checker_utils/get_next_line.h

OBJS = $(SRCS:.c=.o)

#COBJS = $(CSRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)

%.o:%.c
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re