/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   special_sorting.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 13:46:06 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/04 17:50:43 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
/////// special sorting 3
void	special_sort_3(t_stack **lst)
{
	int	a;
	int	b;
	int	c;

	a = (*lst)->data;
	b = (*lst)->next->data;
	c = (*lst)->next->next->data;
	if (a < b && b < c)
	{
		ft_sa(*lst, "sa\n");
		ft_rra(lst, "rra\n");
	}
	else if (a < b && b > c && a > c)
		ft_sa(*lst, "sa\n");
	else if (a < b && b > c && a < c)
		ft_ra(*lst, "ra\n");
	else if (a > b && b < c && a < c)
		ft_rra(lst, "rra\n");
	else if (a > b && b < c && a > c)
	{
		ft_sa(*lst, "sa\n");
		ft_ra(*lst, "ra\n");
	}
	else if (a > b && b > c)
	{
		return ;
	}
	else if (a > b && b < c)
		ft_ra(*lst, "ra\n");
}

// special sorting 5

void    special_first_one(t_stack **lst, t_stack *b)
{
    if (b->data < ft_lstlast(*lst)->data)
		{
			ft_pa(lst, &b, "pa\n");
			ft_ra(*lst, "ra\n");
		}
		else if (b->data < (*lst)->data && b->data > ft_lstlast(*lst)->data)
		{
			if (b->data > (*lst)->next->data)
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
}

void	special_sort_5(t_stack **lst)
{
	t_stack	*b;

	if (ft_lstsize(*lst) == 2)
	{
		if (ft_is_sorted(*lst))
			ft_sa(*lst, "sa\n");
	}
	else if (ft_lstsize(*lst) == 3)
		special_sort_3(lst);
	else
	{
		b = NULL;
		if (ft_lstsize(*lst) == 5)
			ft_pb(lst, &b, "pb\n");
		ft_pb(lst, &b, "pb\n");	
		special_sort_3(lst);
		if (b->data < ft_lstlast(*lst)->data)
		{
			ft_pa(lst, &b, "pa\n");
			ft_ra(*lst, "ra\n");
		}
		else if (b->data < (*lst)->data && b->data > ft_lstlast(*lst)->data)
		{
			if (b->data > (*lst)->next->data)
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
		if (b->data < ft_lstlast(*lst)->data)
		{
			ft_pa(lst, &b, "pa\n");
			ft_ra(*lst, "ra\n");
		}
		else if (b->data < (*lst)->data && b->data > ft_lstlast(*lst)->data)
		{
			if (b->data < (*lst)->next->data)
			{
				if (b->data > (*lst)->next->next->data)
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
			else
			{
				ft_pa(lst, &b, "pa\n");
				ft_sa(*lst, "sa\n");
			}
		}
		else
			ft_pa(lst, &b, "pa\n");
	}
}
*/