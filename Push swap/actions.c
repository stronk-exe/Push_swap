/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-asri <ael-asri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 10:49:39 by ael-asri          #+#    #+#             */
/*   Updated: 2022/02/09 09:26:51 by ael-asri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sa(t_stack *a, char *s)
{
	t_stack	*temp;
	int		res;

	if (ft_lstsize(a) < 2)
		return (0);
	temp = a->next;
	res = temp->data;
	temp->data = a->data;
	a->data = res;
	ft_putstr(s);
	return (1);
}

int	ft_sb(t_stack *b, char *s)
{
	t_stack	*temp;
	int		res;

	if (ft_lstsize(b) < 2)
		return (0);
	temp = b->next;
	res = temp->data;
	temp->data = b->data;
	b->data = res;
	ft_putstr(s);
	return (1);
}

int	ft_pa(t_stack **a, t_stack **b, char *s)
{
	t_stack	*temp;
	t_stack	*t;

	if (ft_lstsize(*b) <= 0)
		return (0);
	t = ft_lstnew((*b)->data);
	if (!t)
		return (0);
	if (b != NULL)
	{
		ft_lstadd_front(a, t);
		temp = *b;
		(*b) = (*b)->next;
		free(temp);
	}
	ft_putstr(s);
	return (1);
}

int	ft_pb(t_stack **a, t_stack **b, char *s)
{
	t_stack	*temp;
	t_stack	*t;

	if (ft_lstsize(*a) <= 0)
		return (0);
	t = ft_lstnew((*a)->data);
	if (!t)
		return (0);
	if (a != NULL)
	{
		ft_lstadd_front(b, t);
		temp = *a;
		(*a) = (*a)->next;
		free(temp);
	}
	ft_putstr(s);
	return (1);
}
