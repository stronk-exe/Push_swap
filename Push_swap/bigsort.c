/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bigsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:49:47 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/03 18:55:52 by ael-asri         ###   ########.fr       */
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

t_stack	*b_is_null(t_stack **lst, t_stack *b)
{
	int	x;

	x = get_min_index(b);
	if (!get_upper(b))
	{
		if (x <= (ft_lstsize(*lst) / 2))
		{
			while (x > 0)
			{
				ft_rb(b, "rb\n");
				x--;
			}
		}
		else
		{
			while (x < ft_lstsize(*lst))
			{
				ft_rrb(&b, "rrb\n");
				x++;
			}
		}
	}
	ft_pa(lst, &b, "pa\n");
	return (b);
}

t_stack	*c_is_null(t_stack **lst, t_stack *c)
{
	int	x;

	x = get_min_index(c);
	if (!get_upper(c))
	{
		if (x <= (ft_lstsize(*lst) / 2))
		{
			while (x > 0)
			{
				ft_rb(c, "rb\n");
				x--;
			}
		}
		else
		{
			while (x < ft_lstsize(*lst))
			{
				ft_rrb(&c, "rrb\n");
				x++;
			}
		}
	}
	ft_pa(lst, &c, "pa\n");
	return (c);
}

void	one_is_null(t_stack	**lst, t_stack *b, t_stack	*c)
{
	if (ft_lstsize(b) && !ft_lstsize(c))
	{
		while (ft_lstsize(b) > 0)
		{
			b = b_is_null(lst, b);
		}
	}
	else if (!ft_lstsize(b) && ft_lstsize(c))
	{
		while (ft_lstsize(c) > 0)
		{
			c = c_is_null(lst, c);
		}
	}
}
/////////////////  b | c to a
void	bctoa(t_stack	**lst, t_stack *b, t_stack	*c)
{
	int	x;
	int	x2;
	int	min;
	int	min2;

	while (ft_lstsize(b) > 0 || ft_lstsize(c) > 0)
	{
		if ((!ft_lstsize(b) && ft_lstsize(c))
			|| (ft_lstsize(b) && !ft_lstsize(c)))
		{
			one_is_null(lst, b, c);
			break ;
		}
		min = get_min_value(b);
		x = get_min_index(b);
		min2 = get_min_value(c);
		x2 = get_min_index(c);
		if (min > min2)
			b = do_action_bctoa(lst, b, x);
		else
			c = do_action_bctoa(lst, c, x2);
	}
}

void	do_action_atobc(t_stack **lst, int	index, int x)
{
	if (x == 1)
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

void	atobc(t_stack	**lst, int mid)
{
	int	index;
//	int	mid;

//	mid = fill_and_sort_array(lst);
	index = get_index(lst, mid);
	if (index < (ft_lstsize(*lst) / 4))
		do_action_atobc(lst, index, 1);
	else
		do_action_atobc(lst, index, 2);
/*	if (ty < (len / 8))
		ft_pb(lst, &b, "pb\n");
	else
		ft_pb(lst, &c, "pb\n");
	return (lst);*/
}
/*
t_stack	**check_bc(t_stack **lst, t_stack *b, t_stack *c, int len, int mid)
{
	int	ty;

	ty = 0;
	while (ty < (len / 4))
	{
		atobc(lst, mid);
		if (ty < (len / 8))
			ft_pb(lst, &b, "pb\n");
		else
			ft_pb(lst, &c, "pb\n");
		ty++;
	}
	return lst;
}

t_stack	*fill_b(t_stack	**lst, t_stack	*b)
{
	if (!b)
		b = NULL;
	ft_pb(lst, &b, "pb\n");
	return (b);
}

t_stack	*fill_c(t_stack	**lst, t_stack	*c)
{
	if (!c)
		c = NULL;
	ft_pb(lst, &c, "pb\n");
	return (c);
}
*/
int recursive_sort(t_stack **lst)
{
	t_stack	*b;
	t_stack	*c;
	int		mid;
	int		ty;
	int		len;

	ty = 0;
	b = NULL;
	c = NULL;
	len = ft_lstsize(*lst);
	mid = fill_and_sort_array(lst);
//	if (!mid)
//		return (NULL);
	while (ty < (len / 4))
	{
		atobc(lst, mid);
		if (ty < (len / 8))
			ft_pb(lst, &b, "pb\n");
		else
			ft_pb(lst, &c, "pb\n");
		ty++;
	}
	if (ft_lstsize(*lst) > 3)
		recursive_sort(lst);
	else
		small_sort(lst);
	bctoa(lst, b, c);
	return (1);
}
