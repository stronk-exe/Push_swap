/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:50:33 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/09 15:40:37 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//# include "Checker_utils/get_next_line.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "checker_utils/get_next_line.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

//////////
char	*ft_strdup(char *s1);
int		ft_strcmp(char	*s1, char	*s2);
/////////////
t_stack	*ft_lstnew(int content);
int		ft_lstsize(t_stack *lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_front(t_stack **lst, t_stack *new);
void	ft_lstadd_back(t_stack **lst, t_stack *new);

////////////////////////////////
////  actions
int		ft_sa(t_stack *a, char *s);
int		ft_sb(t_stack *b, char *s);
int		ft_ss(t_stack *a, t_stack *b, char *s);
int		ft_pa(t_stack **a, t_stack **b, char *s);
int		ft_pb(t_stack **a, t_stack **b, char *s);
int		ft_ra(t_stack *a, char *s);
int		ft_rb(t_stack *b, char *s);
int		ft_rr(t_stack *a, t_stack *b, char *s);
int		ft_rra(t_stack **a, char *s);
int		ft_rrb(t_stack **b, char *s);
int		ft_rrr(t_stack **a, t_stack **b, char *s);

/////////////////////////////////////
//// sorting
int		ft_is_sorted(t_stack *lst);

/////////////// small sort
void	small_sort(t_stack **lst);

t_stack	**new_sort(t_stack **lst);

void	ft_sort_3(t_stack **lst);
void	ft_sort_5(t_stack **lst);

//////////////// big sort
t_stack	**recursive_sort(t_stack **lst);
t_stack	**recursive_sort_2(t_stack **lst);

/////////////////////////////
int		fill_and_sort_array5(t_stack **lst);
t_stack	*do_action_bctoa5(t_stack	**lst, t_stack *b, int x);
///atob
t_stack	*small_one(t_stack **lst, t_stack *b, int chk);
t_stack	*big_one(t_stack **lst, t_stack *b, int chk);
//// btoa
t_stack	**b_to_a(t_stack **lst, t_stack *b);
//////////////// errors
int		ft_isdup(t_stack *a);
int		check_error(t_stack *lst);
int		is_max(t_stack *lst);

int		special_strcmp(char *s1);
////////////////////////////////////////////
/// utils
//int ft_strlen(char *s);
void	ft_putstr(char	*s);
long	ft_atoi(char *s);
int		ft_strlen(char *s);

///////////////
// min max indexes
int		get_max(t_stack **lst, int chk);
int		get_min(t_stack **lst, int chk);
int		get_min_index5(t_stack *lst);
int		get_max_index5(t_stack *lst);
int		get_2th_max_index5(t_stack *lst, int val);

////// get max min values
int		get_min_value5(t_stack *lst);
int		get_2th_max_value5(t_stack *lst, int val);

////////////////
void	ft_sort_array(int *t, int n);
int		get_upper(t_stack *b);
void	special_sort_5(t_stack **lst);
void	special_sort_3(t_stack **lst);
int		get_index(t_stack **lst, int mid);
int		is_upper(t_stack *b, int data);
int		get_s_upper(t_stack *b);

//////////////////////////////////////////
////  Checker
int		get_actions(t_stack **a, t_stack **b);

#endif
