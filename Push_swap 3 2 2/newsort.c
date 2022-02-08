/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:53:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/08 12:55:36 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*do_action_bctoa5(t_stack	**lst, t_stack *b, int x)
{
	if (!get_upper(b))
	{
		if (x <= (ft_lstsize(b) / 2))
		{
			while (x > 0)
			{
				ft_rb(b, "rb\n");
				x--;
			}
		}
		else
		{
			while (x < ft_lstsize(b))
			{
				ft_rrb(&b, "rrb\n");
				x++;
			}
		}
		ft_pa(lst, &b, "pa\n");
	}
	else
		ft_pa(lst, &b, "pa\n");
	return (b);
}

int	fill_and_sort_array5(t_stack **lst)
{
	t_stack	*cp;
	int		i;
	int		*t;
	int		mid;

	i = 0;
	cp = *lst;
	t = malloc(sizeof(int) * (ft_lstsize(*lst) + 1));
//	if (!t)
//		return (NULL);
	while (cp != NULL)
	{
		t[i] = cp->data;
		cp = cp->next;
		i++;
	}
	t[i] = '\0';
	ft_sort_array(t, i);
	mid = t[ft_lstsize(*lst) / 2];
	return (mid);
}

t_stack	**new_sort(t_stack **lst)
{
	t_stack	*b;
	int		chk;

	b = NULL;
	if (ft_lstsize(*lst) <= 100)
	{
		chk = (ft_lstsize(*lst) / 9);
		b = small_one(lst, b, chk);
	}
	else
	{
		chk = (ft_lstsize(*lst) / 17);
		b = big_one(lst, b, chk);
	}
	lst = b_to_a(lst, b);
	return (lst);
}
