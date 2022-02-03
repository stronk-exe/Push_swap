/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:49:47 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/03 20:31:41 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*do_action_bctoa(t_stack	**lst, t_stack *bc, int x)
{
	if (!get_upper(bc))
	{
		if (x <= (ft_lstsize(bc) / 2))
		{
			while (x > 0)
			{
				ft_rb(bc, "rb\n");
				x--;
			}
		}
		else
		{
			while (x < ft_lstsize(bc))
			{
				ft_rrb(&bc, "rrb\n");
				x++;
			}
		}
		ft_pa(lst, &bc, "pa\n");
	}
	else
		ft_pa(lst, &bc, "pa\n");
	return (bc);
}

int	get_min_value(t_stack *lst)
{
	int	min;
	int	j;

	j = 0;
	min = lst->data;
	while (lst != NULL)
	{
		if (min < lst->data)
			min = lst->data;
		lst = lst->next;
		j++;
	}
	return (min);
}

int	get_min_index(t_stack *lst)
{
	int	min;
	int	j;
	int	x;

	x = 0;
	j = 0;
	min = lst->data;
	while (lst != NULL)
	{
		if (min < lst->data)
		{
			min = lst->data;
			x = j;
		}
		lst = lst->next;
		j++;
	}
	return (x);
}

/////////////////  b | c to a
void	bctoa(t_stack	**lst, t_stack *b)
{
	int	x;
	int	min;

	while (ft_lstsize(b) > 0)
	{
		min = get_min_value(b);
		x = get_min_index(b);
		b = do_action_bctoa(lst, b, x);
	}
}

int	fill_and_sort_array(t_stack **lst)
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
	mid = t[ft_lstsize(*lst) / 4];
	return (mid);
}

int recursive_sort(t_stack **lst)
{
	t_stack	*b;
	int		mid;
	int		ty;
	int		len;
	int	index;

	ty = 0;
	b = NULL;
	len = ft_lstsize(*lst);
	mid = fill_and_sort_array(lst);
//	if (!mid)
//		return (NULL);
	while (ty < (len / 4))
	{
		index = get_index(lst, mid);
		if (index < ft_lstsize(*lst) / 2)
		{
			while (index > 0)
			{
				ft_ra(*lst, "ra\n");
				index--;
			}
		}
		else
		{
			while (index < ft_lstsize(*lst))
			{
				ft_rra(lst, "rra\n");
				index++;
			}
		}
		ft_pb(lst, &b, "pb\n");
		ty++;
	}
	if (ft_lstsize(*lst) > 5)
		recursive_sort(lst);
	else
		small_sort(lst);
	bctoa(lst, b);
	return (1);
}
