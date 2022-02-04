/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 20:36:04 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/04 16:41:02 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*do_action_btoa2(t_stack	**lst, t_stack *b, int x)
{
//	printf("weshhhhhhh %d\n", x);
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

int	get_min_value2(t_stack *lst)
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

int	get_min_index2(t_stack *lst)
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
void	btoa2(t_stack	**lst, t_stack *b)
{
	int	x;
//	int	min;

	while (ft_lstsize(b) > 0)
	{
//		min = get_min_value2(b);
		x = get_min_index2(b);
		b = do_action_btoa2(lst, b, x);
	}
}

int	fill_and_sort_array2(t_stack **lst)
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
	mid = t[ft_lstsize(*lst) / 7];
	return (mid);
}

void	actions_in_a2(t_stack **lst, int mid)
{
	int	index;

	index = get_index(lst, mid);
	if (index <= ft_lstsize(*lst) / 2)
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
}

int recursive_sort_2(t_stack **lst)
{
	t_stack	*b;
	int		mid;
	int		ty;
	int		len;

	ty = 0;
	b = NULL;
	len = ft_lstsize(*lst);
	mid = fill_and_sort_array2(lst);
//	if (!mid)
//		return (NULL);
	while (ty < (len / 7))   // 4/5 -----------   9->7087 | 8->7040 | 7->6858 | 6->7008
	{
		actions_in_a2(lst, mid);
		ft_pb(lst, &b, "pb\n");
		ty++;
	}
	if (ft_lstsize(*lst) >= 7)
		recursive_sort_2(lst);
	else
		recursive_sort(lst);
	btoa2(lst, b);
	return (1);
}
