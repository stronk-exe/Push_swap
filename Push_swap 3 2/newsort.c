/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newsort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:53:37 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/06 21:20:11 by ael-asri         ###   ########.fr       */
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

int	get_min_value5(t_stack *lst)
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

int	get_min_index5(t_stack *lst)
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
void	btoa5(t_stack	**lst, t_stack *b)
{
	int	x;
//	int	min;

	while (ft_lstsize(b) > 0)
	{
//		min = get_min_value(b);
		x = get_min_index5(b);
		b = do_action_bctoa5(lst, b, x);
	}
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
//	int min = t[mid - 12];
//	int max = t[mid + 12];
	return (mid);
}

int	*faww(t_stack **lst)
{
	t_stack	*cp;
	int		i;
	int		*t;
//	int		mid;

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
//	int min = t[mid - 12];
//	int max = t[mid + 12];
	return (t);
}

int	get_max(t_stack **lst, int chk)
{
	t_stack	*cp;
	int		i;
	int		*t;
	int		max;

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
	max = t[(ft_lstsize(*lst) / 2) + chk];
	return (max);
}
/*
int	get_new_max(t_stack **lst, int chk)
{
	t_stack	*cp;
	int		i;
	int		*t;
	int		max;

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
	*/

/*	while (t[i] != mid)
	{
		i++;
	}*/
//	i = 0;
//	max = t[chk];
//	return (max);
//}

int	get_min(t_stack **lst, int chk)
{
	t_stack	*cp;
	int		i;
	int		*t;
	int		min;

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
	min = t[(ft_lstsize(*lst) / 2) - chk];
	return (min);
}
/*
int	get_new_min(t_stack **lst, int mid, int chk)
{
	t_stack	*cp;
	int		i;
	int		*t;
	int		min;

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
	i = 0;
	while (t[i] != mid)
	{
		i++;
	}
//	i = 0;
	min = t[i - chk];
	return (min);
}
*/
/*void	actions_in_a5(t_stack **lst, int mid)
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
}*/

t_stack **new_sort(t_stack **lst)
{
	t_stack	*b;
	int		mid;
	int		ty;
	int		len;
	int		chk;
	int		max;
	int		min;
	int		i;

//	static	int	mid;
//	ty = 0;
	b = NULL;
	len = ft_lstsize(*lst);
	i = 0;
//	mid = fill_and_sort_array5(lst);
//	max = fill_and_sort_array5(lst);
//	max = get_max(lst);
//	if (!mid)
//		return (NULL);
	if (ft_lstsize(*lst) < 150)
	{
	/*	chk = (len / 8);
		while (ft_lstsize(*lst) > (len / 2))
		{
			ty = 0;
		//	mid = fill_and_sort_array5(lst);
		//	printf("midddd %d\n", mid);
			min = get_new_min(lst, mid, chk);
		//	printf("min %d\n", min);
			while (ty < (chk) && ft_lstsize(*lst) > (len / 2))
			{
		//		printf("lst %d\n", (*lst)->data);
				if (((*lst)->data < mid && (*lst)->data >= min) || (ft_lstsize(*lst) - (len / 2)) <= chk)
				{
					ft_pb(lst, &b, "pb\n");
					ty++;
				}
				else
				{
					ft_ra(*lst, "ra\n");
				}
			//	actions_in_a(lst, mid);
			//	ft_pb(lst, &b, "pb\n");
		//		printf("wa ty %d\n", ty);
		//		printf("miiin %d\n", min);
		//		printf("maxx %d\n", max);
			//	printf("chkk %d\n", chk);
		//		printf("len %d\n", (ft_lstsize(*lst)));
		//		printf("lssst b %d\n", ft_lstsize(b));
			}
		}
//		printf("----------------len %d\n", (ft_lstsize(*lst)));
		while (ft_lstsize(*lst) > 0)
		{
			ty = 0;
		//	mid = fill_and_sort_array5(lst);
			max = get_new_max(lst, chk);
			while (ty < (chk) && ft_lstsize(*lst) > 0)
			{
				if (((*lst)->data <= max && (*lst)->data > mid) || (ft_lstsize(*lst) <= chk))
				{
					ft_pb(lst, &b, "pb\n");
				//	ft_rb(b, "rb\n");
					ty++;
				}
				else
				{
					ft_ra(*lst, "ra\n");
				//	printf("maxx %d\n", max);
				//	printf("lst %d\n", (*lst)->data);
				//	printf("----------------len %d\n", (ft_lstsize(*lst)));
				}
			}
		}*/
	/*	int wiw = chk;
		while (ft_lstsize(*lst) > 0)
		{
			ty = 0;
		//	mid = fill_and_sort_array5(lst);
		//	max = get_new_max(lst, chk, len);
			int *t;
			t = faww(lst);
			wiw = wiw + chk;
			max = t[wiw];
			while (ty < (chk) && ft_lstsize(*lst) > 0)
			{
				printf("wiiw %d\n", wiw);
				printf("lst %d\n", (*lst)->data);
				if (((*lst)->data <= max && (*lst)->data > mid)*//* || (ft_lstsize(*lst) <= chk)*//*)
				{
					ft_pb(lst, &b, "pb\n");
					ft_rb(b, "rb\n");
					ty++;
				}
				else
				{
					ft_ra(*lst, "ra\n");
				}
			//	actions_in_a(lst, mid);
			//	ft_pb(lst, &b, "pb\n");
				printf("ho ty %d\n", ty);
				printf("maaax %d\n", max);
				printf("midddd %d\n", mid);
				printf("chkk %d\n", chk);
				printf("len %d\n", ft_lstsize(*lst));
				printf("lssst b %d\n", ft_lstsize(b));
			}
		}*/
		chk = (len / 8);
		while (ft_lstsize(*lst) > 0)
		{
			ty = 0;
			mid = fill_and_sort_array5(lst);
			max = get_max(lst, chk);
			min = get_min(lst, chk);
			while (ty <= (chk * 2) && ft_lstsize(*lst) > 0)
			{
				if (((*lst)->data <= mid && (*lst)->data >= min) || ft_lstsize(*lst) <= chk)
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
				{
					ft_ra(*lst, "ra\n");
				}
			}
		}
	}
	else
	{
		chk = (len / 18);
		while (ft_lstsize(*lst) > 0)
		{
			ty = 0;
			mid = fill_and_sort_array5(lst);
			max = get_max(lst, chk);
			min = get_min(lst, chk);
			while (ty <= (chk * 2) && ft_lstsize(*lst) > 0)
			{
				if (((*lst)->data <= mid && (*lst)->data >= min) || ft_lstsize(*lst) <= chk)
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
				{
					ft_ra(*lst, "ra\n");
				}
			}
		}
	}
	btoa5(lst, b);
	return (lst);
}