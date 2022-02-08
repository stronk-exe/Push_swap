/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minmax_indexes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:01:06 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/08 12:11:35 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	get_min_index5(t_stack *lst)
{
	int	min;
	int	j;
	int	x;

	x = 0;
	j = 0;
	if (ft_lstsize(lst) > 0)
	{
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
	}
	return (x);
}

int	get_max_index5(t_stack *lst)
{
	int	max;
	int	j;
	int	x;

	x = 0;
	j = 0;
	max = lst->data;
	while (lst != NULL)
	{
		if (max < lst->data)
		{
			max = lst->data;
			x = j;
		}
		lst = lst->next;
		j++;
	}
	return (x);
}

int	get_2th_max_index5(t_stack *lst, int val)
{
	int	max;
	int	j;
	int	x;

	x = 0;
	j = 0;
	max = lst->data;
	while (lst != NULL)
	{
		if (max < lst->data && lst->data < val)
		{
			max = lst->data;
			x = j;
		}
		lst = lst->next;
		j++;
	}
	return (x);
}
