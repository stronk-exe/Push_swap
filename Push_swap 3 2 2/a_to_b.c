/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:46:06 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/08 13:24:33 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*one_for_small(t_stack **lst, t_stack *b, int chk, int mid)
{
	int		ty;
	int		max;
	int		min;

	ty = 0;
	max = get_max(lst, chk);
	min = get_min(lst, chk);
	while (ty <= (chk * 2) && ft_lstsize(*lst) > 0)
	{
		if (((*lst)->data <= mid && (*lst)->data >= min)
			|| ft_lstsize(*lst) <= chk)
		{
			ft_pb(lst, &b, "pb\n");
				ty++;
		}
		else if ((*lst)->data <= max && (*lst)->data > mid)
		{
			ft_pb(lst, &b, "pb\n");
			if ((*lst)->data < min || (*lst)->data > max)
				ft_rr(*lst, b, "rr\n");
			else
				ft_rb(b, "rb\n");
			ty++;
		}
		else
			ft_ra(*lst, "ra\n");
	}
	return (b);
}

t_stack	*one_for_big(t_stack **lst, t_stack *b, int chk, int mid)
{
	int		ty;
	int		max;
	int		min;

	ty = 0;
	max = get_max(lst, chk);
	min = get_min(lst, chk);
	while (ty <= (chk * 2) && ft_lstsize(*lst) > 0)
	{
		if (((*lst)->data <= mid && (*lst)->data >= min)
			|| ft_lstsize(*lst) <= chk)
		{
			ft_pb(lst, &b, "pb\n");
			ty++;
		}
		else if ((*lst)->data <= max && (*lst)->data > mid)
		{
			ft_pb(lst, &b, "pb\n");
			if ((*lst)->data < min || (*lst)->data > max)
				ft_rr(*lst, b, "rr\n");
			else
				ft_rb(b, "rb\n");
			ty++;
		}
		else
			ft_ra(*lst, "ra\n");
	}
	return (b);
}

t_stack	*small_one(t_stack **lst, t_stack *b, int chk)
{
	int		mid;
	int		ty;

	while (ft_lstsize(*lst) > 0)
	{
		ty = 0;
		mid = fill_and_sort_array5(lst);
		while (ty <= (chk * 2) && ft_lstsize(*lst) > 0)
		{
		//	ty = 0;
		//	mid = fill_and_sort_array5(lst);
            b = one_for_small(lst, b, chk, mid);
		}
	}
	return (b);
}

t_stack	*big_one(t_stack **lst, t_stack *b, int chk)
{
	int		mid;
	int		ty;

	while (ft_lstsize(*lst) > 0)
	{
		ty = 0;
		mid = fill_and_sort_array5(lst);
		while (ty <= (chk * 2) && ft_lstsize(*lst) > 0)
		{
		//	ty = 0;
		//	mid = fill_and_sort_array5(lst);
            b = one_for_big(lst, b, chk, mid);
		}
	}
	return (b);
}
