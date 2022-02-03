/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:51:03 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/02 14:50:53 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack **lst)
{
	int	a;
	int	b;
	int	c;

	a = (*lst)->data;
	b = (*lst)->next->data;
	c = (*lst)->next->next->data;
	if (a < b && b > c && a > c)
		ft_rra(lst, "rra\n");
	else if (a < b && b > c && a < c)
	{
		ft_sa(*lst, "sa\n");
		ft_ra(*lst, "ra\n");
	}
	else if (a > b && b < c && a < c)
		ft_sa(*lst, "sa\n");
	else if (a > b && b < c && a > c)
		ft_ra(*lst, "ra\n");
	else if (a > b && b > c)
	{
		ft_sa(*lst, "sa\n");
		ft_rra(lst, "rra\n");
	}
	else if (a > b && b < c)
		ft_ra(*lst, "ra\n");
}

void	yoyo(t_stack **lst, t_stack *b)
{
	if (b->data < (*lst)->next->next->data)
	{
		ft_ra(*lst, "ra\n");
		ft_pa(lst, &b, "pa\n");
		ft_sa(*lst, "sa\n");
		ft_rra(lst, "rra\n");
	}
	else
	{
		ft_rra(lst, "rra\n");
		ft_pa(lst, &b, "pa\n");
		ft_ra(*lst, "ra\n");
		ft_ra(*lst, "ra\n");
	}
}

void	another_one(t_stack **lst, t_stack *b)
{
	if (b->data > ft_lstlast(*lst)->data)
	{
		ft_pa(lst, &b, "pa\n");
		ft_ra(*lst, "ra\n");
	}
	else if (b->data > (*lst)->data && b->data < ft_lstlast(*lst)->data)
	{
		if (b->data > (*lst)->next->data)
			yoyo(lst, b);
		else
		{
			ft_pa(lst, &b, "pa\n");
			ft_sa(*lst, "sa\n");
		}
	}
	else
		ft_pa(lst, &b, "pa\n");
}

void	first_one(t_stack **lst, t_stack *b)
{
	if (b->data > ft_lstlast(*lst)->data)
	{
		ft_pa(lst, &b, "pa\n");
		ft_ra(*lst, "ra\n");
	}
	else if (b->data > (*lst)->data && b->data < ft_lstlast(*lst)->data)
	{
		if (b->data < (*lst)->next->data)
		{
			ft_pa(lst, &b, "pa\n");
			ft_sa(*lst, "sa\n");
		}
		else
		{
			ft_ra(*lst, "ra\n");
			ft_pa(lst, &b, "pa\n");
			ft_sa(*lst, "sa\n");
			ft_rra(lst, "rra\n");
		}
	}
	else
		ft_pa(lst, &b, "pa\n");
	if (b == NULL)
		return ;
	another_one(lst, b);
}
/*
void	ft_sort_5(t_stack **lst)
{
	t_stack	*b;

	b = NULL;
	if (ft_lstsize(*lst) == 5)
		ft_pb(lst, &b, "pb\n");
	ft_pb(lst, &b, "pb\n");
	ft_sort_3(lst);
	first_one(lst, b);
}
*/

void	small_sort(t_stack **lst)
{
	t_stack	*b;

	b = NULL;
	if (ft_lstsize(*lst) == 2)
	{
		if (!ft_is_sorted(*lst))
			ft_sa(*lst, "sa\n");
	}
	else if (ft_lstsize(*lst) == 3)
		ft_sort_3(lst);
	else if (ft_lstsize(*lst) <= 5)
	{
		if (ft_lstsize(*lst) == 5)
			ft_pb(lst, &b, "pb\n");
		ft_pb(lst, &b, "pb\n");
		ft_sort_3(lst);
		first_one(lst, b);
	}
}
