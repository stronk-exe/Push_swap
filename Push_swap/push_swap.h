/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:55:57 by ael-asri          #+#    #+#             */
/*   Updated: 2022/01/14 00:59:16 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Checker_utils/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_lstnew(int content);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);



//////////////////////////////////////////
////  Checker
int	get_actions(t_stack **a, t_stack **b);
int	ft_strcmp(const char *s1, const char *s2);

////////////////////////////////
////  actions


void	ft_sa(t_stack *a, char *s);
void	ft_sb(t_stack *b, char *s);
void	ft_ss(t_stack *a, t_stack *b, char *s);
void	ft_pa(t_stack **a, t_stack **b, char *s);
void	ft_pb(t_stack **a, t_stack **b, char *s);
void	ft_ra(t_stack *a, char *s);
void	ft_rb(t_stack *b, char *s);
void	ft_rr(t_stack *a, t_stack *b, char *s);
void	ft_rra(t_stack **a, char *s);
void	ft_rrb(t_stack **b, char *s);
void	ft_rrr(t_stack **a, t_stack **b, char *s);
int ft_is_sorted(t_stack *lst);


/////////////////////////////////////
///// errors
int	ft_isdup(t_stack *a);
int check_error(t_stack *lst);
int is_max(t_stack *lst);

////////////////////////////////////////////
/// utils
void	ft_putstr(char	*s);
int		ft_atoi(char *s);

///////////////
void ft_sort_array(int *t, int n);
int get_upper(t_stack *b);
void	special_sort_5(t_stack **lst);
void	special_sort_3(t_stack **lst);
int get_index(t_stack **lst, int mid);
int is_upper(t_stack *b, int data);
#endif